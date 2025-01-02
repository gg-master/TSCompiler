#include "class_analyzer.h"

void ClassAnalyzer::attributeClass(ClassDeclarationNode *node)
{
    currentClass = node;

    if (currentClass->className.starts_with("JavaRTL"))
        return;

    resolveClassConstructor();
    attributeMemberSignatures();
}

void ClassAnalyzer::resolveClassConstructor()
{
    std::vector<ClassElementNode *> constructors =
        currentClass->body->GetConstructors();

    if (constructors.empty())
    {
        auto *constructor =
            new ClassElementNode{RequiredParameterListNode::makeEmpty(),
                                 StatementListNode::makeEmpty()};
        currentClass->body->add(constructor);
    }

    if (constructors.size() > 1)
    {
        errors.emplace_back(
            "Multiple constructor implementations are not allowed.");
    }

    // TODO add inheritance support (here need to resolve default constructor)
    if (!currentClass->heritageName.empty())
    {
        errors.emplace_back("Inheritance is not supported in this version.");
    }
}

void ClassAnalyzer::attributeMemberSignatures()
{
    for (auto *method : currentClass->body->GetSeq())
    {
        if (method->type == ClassElementNode::Type::_PROPERTY)
            continue;

        currentMethod = method;

        method->elemClass = currentClass;

        auto *type = toJvmDataType(method->propertyAndReturnType);
        if (*type == RTL_ANY_TYPE)
        {
            type = new JvmDataType(JvmDataType::Type::Void);
        }
        method->propertyAndReturnType = new TypeNode(type);

        method->analyzeArguments();

        for (auto *arg : method->params->GetSeq())
        {
            analyzeRequiredParam(arg);
        }
    }
    for (ClassElementNode *node : currentClass->body->GetProperties())
    {
        attributeClassProperty(node);
    }
}

void ClassAnalyzer::analyzeRequiredParam(RequiredParameterNode *param)
{
    validateTypename(param->paramType->jvmType);

    auto const &methodVariables = currentMethod->variables;
    auto const foundVariable =
        std::find_if(methodVariables.begin(), methodVariables.end(),
                     [&](VarDeclarationNode *var)
                     { return var->identifierStr == param->paramName; });
    if (foundVariable != methodVariables.end())
    {
        errors.push_back("Duplicate identifier '" + param->paramName + "'");
        return;
    }

    auto *varDecl =
        new VarDeclarationNode(param->paramName, param->paramType, nullptr);
    varDecl->scopingLevel = currentScopingLevel;

    currentMethod->variables.push_back(varDecl);
}

void ClassAnalyzer::attributeClassProperty(ClassElementNode *node)
{
    node->elemClass = currentClass;
    node->propertyAndReturnType->jvmType =
        toJvmDataType(node->propertyAndReturnType);
    validateTypename(node->propertyAndReturnType->jvmType);

    auto *found = currentClass->body->findPropertyByName(node->name);
    if (found && found != node)
    {
        errors.push_back("Duplicate identifier '" + node->name + "'");
        return;
    }
}

void ClassAnalyzer::analyzeClass(ClassDeclarationNode *node)
{
    currentClass = node;

    if (currentClass->className.starts_with("JavaRTL"))
        return;

    analyzeClassConstructor();
}

void ClassAnalyzer::analyzeClassConstructor()
{
    ClassElementNode *constructor = currentClass->body->GetConstructors()[0];

    // TODO add constructor checks for super call
    if (!currentClass->heritageName.empty())
    {
        auto const &body = constructor->methodBody->GetSeq();
        auto const superCallStmt = std::find_if(
            body.begin(), body.end(),
            [&](StatementNode *stmt)
            {
                return stmt->type == StatementNode::Type::_EXPRESSION &&
                       stmt->expression->type ==
                           ExpressionNode::Type::_SUPER_CALL;
            });

        if (superCallStmt == body.end())
        {
            errors.push_back(
                "Constructors for derived classes must contain a 'super' "
                "call.");
        }
        else if (superCallStmt != body.begin())
        {
            errors.push_back(
                "A 'super' call must be the first statement in the "
                "constructor");
        }
        else
        {
            errors.push_back(
                "A 'super' call is not supported in this version.");
        }
    }

    constructor->elemClass = currentClass;
    currentMethod = constructor;

    currentScopingLevel = 1;

    auto *thisVar = new VarDeclarationNode(
        "this", new TypeNode(currentClass->toDataType()), nullptr);
    currentMethod->variables.push_back(thisVar);

    // move function scoped variables ("var") on top of the function
    for (auto *stmt : currentMethod->methodBody->GetSeq())
    {
        for (auto *existVarDecl : stmt->getAllFunctionScopedVars())
        {
            existVarDecl->scopingLevel = currentScopingLevel;

            auto *varDecl = new VarDeclarationNode(
                existVarDecl->identifierStr, existVarDecl->varType, nullptr);

            varDecl->scopingLevel = currentScopingLevel;
            currentMethod->variables.push_back(varDecl);
        }
    }

    incrementScopingLevel();

    for (auto *stmt : currentMethod->methodBody->GetSeq())
    {
        analyzeStmt(stmt);
    }
    decrementScopingLevel();

    if (!currentMethod->methodBody->isEmpty())
    {
        auto *lastStmt = currentMethod->methodBody->GetSeq().back();
        if (lastStmt->type == StatementNode::Type::_RETURN &&
            *lastStmt->expression->exprType != *thisVar->varType)
        {
            errors.push_back(
                "Return type of constructor signature must be assignable to "
                "the instance type of the class.");
        }
    }

    currentMethod = nullptr;
}

void ClassAnalyzer::analyzeStmt(StatementNode *node)
{
    if (!node)
        return;

    node->expression = analyzeExpr(node->expression);
}

void ClassAnalyzer::analyzeClassProperty(ClassElementNode *node,
                                         bool checkConstructorInit)
{
    if (!node)
        return;

    node->expression = analyzeExpr(node->expression);
}

ExpressionNode *ClassAnalyzer::analyzeExpr(ExpressionNode *node)
{
    if (!node)
        return nullptr;

    auto changed = replaceAssignmentsOnArrayElements(node);
    changed->applyToAllChildren(replaceAssignmentsOnArrayElements);

    analyzeFuncCall(changed);
    analyzeMethodCall(changed);

    changed->callForAllChildren(
        [this](ExpressionNode *changed)
        {
            analyzeFuncCall(changed);
            analyzeMethodCall(changed);
        });

    calculateTypeForExpr(changed);

    changed = replaceAssignmentsOnField(changed);
    changed->applyToAllChildren(replaceAssignmentsOnField);

    calculateTypeForExpr(changed);

    return changed;
}

void ClassAnalyzer::analyzeFuncCall(ExpressionNode *node)
{
    if (!node || node->type != ExpressionNode::Type::_FUNC_CALL)
        return;

    for (auto argument : node->params->GetSeq())
        argument = analyzeExpr(argument);

    node->exprType = new TypeNode(new JvmDataType(RTL_ANY_TYPE));

    const auto funcName = node->identifierString;
    const auto callTypes = [node, this]()
    {
        auto const &arguments = node->params->GetSeq();
        std::vector<JvmDataType> types(arguments.size());
        std::transform(arguments.begin(), arguments.end(), types.begin(),
                       [this](ExpressionNode *arg)
                       {
                           validateTypename(arg->exprType->jvmType);
                           return *arg->exprType->jvmType;
                       });
        return types;
    }();

    auto const &allFunctions = root->mainClass->body->GetMethods();
    const auto foundFunc =
        std::find_if(allFunctions.begin(), allFunctions.end(),
                     [&](ClassElementNode *func) {
                         return funcName == func->name &&
                                callTypes == func->params->getTypes();
                     });

    if (foundFunc == allFunctions.end())
    {
        errors.push_back("Cannot call function with name " + funcName +
                         " with arguments of types " + toString(callTypes));
        return;
    }
    node->exprType = (*foundFunc)->propertyAndReturnType;
    node->actualMethodCall = *foundFunc;
}

void ClassAnalyzer::analyzeMethodCall(ExpressionNode *node)
{
    if (!node || node->type != ExpressionNode::Type::_METHOD_CALL)
        return;

    for (auto argument : node->params->GetSeq())
        argument = analyzeExpr(argument);

    node->exprType = new TypeNode(new JvmDataType(RTL_ANY_TYPE));

    analyzeExpr(node->firstOperand);
    const auto objType = calculateTypeForExpr(node->firstOperand);

    auto *foundClass = findClass(node->firstOperand->exprType->jvmType);

    if (!foundClass)
    {
        errors.push_back("Property '" + node->identifierString +
                         "' does not exist on type '" + objType->toString() +
                         "'.");
        return;
    }

    const auto methodName = node->identifierString;
    const auto callTypes = [node, this]()
    {
        auto const &arguments = node->params->GetSeq();
        std::vector<JvmDataType> types(arguments.size());
        std::transform(arguments.begin(), arguments.end(), types.begin(),
                       [this](ExpressionNode *arg)
                       {
                           validateTypename(arg->exprType->jvmType);
                           return *arg->exprType->jvmType;
                       });
        return types;
    }();

    auto const &allMethod = foundClass->body->GetMethods();
    const auto foundMethod =
        std::find_if(allMethod.begin(), allMethod.end(),
                     [&](ClassElementNode *func) {
                         return methodName == func->name &&
                                callTypes == func->params->getTypes();
                     });

    if (foundMethod == allMethod.end())
    {
        errors.push_back("Cannot call method with name " + methodName +
                         " with arguments of types " + toString(callTypes));
        return;
    }
    node->exprType = (*foundMethod)->propertyAndReturnType;
    node->actualMethodCall = *foundMethod;
}

void ClassAnalyzer::analyzeNewCall(ExpressionNode *node)
{
    for (auto argument : node->params->GetSeq())
        argument = analyzeExpr(argument);

    node->exprType = new TypeNode(new JvmDataType(node->identifierString));

    auto *foundClass = root->findClass(node->identifierString);

    if (!foundClass)
    {
        errors.push_back("Cannot find name '" + node->identifierString + "'");
        return;
    }

    const auto constructorName = node->identifierString;
    const auto callTypes = [node, this]()
    {
        auto const &arguments = node->params->GetSeq();
        std::vector<JvmDataType> types(arguments.size());
        std::transform(arguments.begin(), arguments.end(), types.begin(),
                       [this](ExpressionNode *arg)
                       {
                           validateTypename(arg->exprType->jvmType);
                           return *arg->exprType->jvmType;
                       });
        return types;
    }();

    auto const &allConstructors = foundClass->body->GetConstructors();
    const auto foundConstructor =
        std::find_if(allConstructors.begin(), allConstructors.end(),
                     [&](ClassElementNode *func)
                     {
                         return constructorName == func->name &&
                                callTypes == func->params->getTypes();
                     });

    if (foundConstructor == allConstructors.end())
    {
        errors.push_back("Cannot call constructor with name " +
                         constructorName + " with arguments of types " +
                         toString(callTypes));
        return;
    }
    node->actualMethodCall = *foundConstructor;
}

TypeNode *ClassAnalyzer::calculateTypeForExpr(ExpressionNode *node)
{
    if (!node)
        return nullptr;

    TypeNode *type;

    if (node->type == ExpressionNode::Type::_INT_LIT)
    {
        type = new TypeNode(new JvmDataType(JvmDataType::Type::Int));
        node->exprType = type;
        return type;
    }
    if (node->type == ExpressionNode::Type::_FLOAT_LIT)
    {
        type = new TypeNode(new JvmDataType(JvmDataType::Type::Float));
        node->exprType = type;
        return type;
    }
    if (node->type == ExpressionNode::Type::_BOOLEAN_LIT)
    {
        type = new TypeNode(new JvmDataType(JvmDataType::Type::Bool));
        node->exprType = type;
        return type;
    }
    if (node->type == ExpressionNode::Type::_STRING_LIT)
    {
        type = new TypeNode(new JvmDataType(JvmDataType::Type::String));
        node->exprType = type;
        return type;
    }
    if (node->type == ExpressionNode::Type::_NULL_LIT)
    {
        type = new TypeNode(new JvmDataType(RTL_NULL_TYPE));
        node->exprType = type;
        return type;
    }
    if (node->type == ExpressionNode::Type::_UNDEFINED_LIT)
    {
        type = new TypeNode(new JvmDataType(RTL_UNDEFINED_TYPE));
        node->exprType = type;
        return type;
    }
    if (node->type == ExpressionNode::Type::_ARRAY_LENGTH)
    {
        return node->exprType;
    }
    if (node->type == ExpressionNode::Type::_ARRAY_CREATION)
    {
        if (auto elements = node->params->GetSeq(); !elements.empty())
        {
            for (auto elem : elements)
            {
                calculateTypeForExpr(elem);
            }
            auto *elemType = elements.front()->exprType->jvmType;

            std::vector<JvmDataType> types(elements.size());
            std::transform(elements.begin(), elements.end(), types.begin(),
                           [](ExpressionNode *node)
                           { return *node->exprType->jvmType; });

            const bool allElementsHaveSameType = std::all_of(
                types.begin(), types.end(),
                [elemType](JvmDataType other) { return *elemType == other; });

            if (!allElementsHaveSameType)
            {
                errors.push_back("Cannot create array with different types: " +
                                 toString(types));
                return new TypeNode(new JvmDataType());
            }
            node->exprType = new TypeNode(new JvmDataType(*elemType));
            node->exprType->jvmType->arrayArity++;
            node->exprType->arrayArity++;
            return node->exprType;
        }
        return new TypeNode(new JvmDataType());
    }
    if (node->type == ExpressionNode::Type::_IDENTIFIER)
    {
        if (currentMethod)
        {
            auto *var = currentMethod->findVariableByName(
                node->identifierString, currentScopingLevel);
            if (var)
            {
                type = var->varType;
                node->exprType = type;
                node->actualVar = var;
                return type;
            }
        }

        if (currentClass)
        {
            auto *var =
                currentClass->body->findPropertyByName(node->identifierString);
            if (var)
            {
                type = var->propertyAndReturnType;
                node->exprType = type;
                node->actualField = var;
                return type;
            }
        }

        auto *var =
            root->mainClass->body->findPropertyByName(node->identifierString);
        if (var)
        {
            type = var->propertyAndReturnType;
            node->exprType = type;
            node->actualField = var;
            return type;
        }

        errors.push_back("Cannot find name '" + node->identifierString + "'");

        type = new TypeNode(new JvmDataType());
        node->exprType = type;
        return type;
    }
    if (node->type == ExpressionNode::Type::_NEW)
    {
        if (!node->actualMethodCall)
        {
            analyzeNewCall(node);
        }
        return node->exprType;
    }
    if (node->type == ExpressionNode::Type::_FUNC_CALL)
    {
        if (!node->actualMethodCall)
        {
            analyzeFuncCall(node);
        }
        return node->exprType;
    }
    if (node->type == ExpressionNode::Type::_METHOD_CALL)
    {
        if (!node->actualMethodCall)
        {
            analyzeMethodCall(node);
        }
        return node->exprType;
    }
    if (node->type == ExpressionNode::Type::_ARRAY_ACCESS)
    {
        auto firstOperand = calculateTypeForExpr(node->firstOperand);
        auto secondOperand = calculateTypeForExpr(node->secondOperand);

        type = firstOperand;
        node->exprType = firstOperand;

        if (secondOperand->jvmType->arrayArity != 0 ||
            (*secondOperand->jvmType != RTL_NUMBER_TYPE ||
             *secondOperand->jvmType != JvmDataType(JvmDataType::Type::Int)))
        {
            errors.push_back("Array index must be type int, not " +
                             secondOperand->toString());
            return type;
        }

        if (secondOperand->jvmType->arrayArity == 0)
        {
            errors.push_back("Cannot use operator[] on type" +
                             type->toString());
            return type;
        }
        return type;
    }
    if (node->type == ExpressionNode::Type::_FIELD_ACCESS)
    {
        auto firstOperand = calculateTypeForExpr(node->firstOperand);

        if (firstOperand->arrayArity > 0 && node->identifierString == "length")
        {
            node->type = ExpressionNode::Type::_ARRAY_LENGTH;

            type = new TypeNode(new JvmDataType(JvmDataType::Type::Int));
            node->exprType = type;
            return type;
        }
        auto *foundClass = findClass(firstOperand->jvmType);
        if (!foundClass)
        {
            errors.push_back("No member " + node->identifierString +
                             " in type " + firstOperand->toString());
            node->exprType = new TypeNode(new JvmDataType());;
            return node->exprType;
        }
        auto foundProp =
            foundClass->body->findPropertyByName(node->identifierString);
        if (!foundProp)
        {
            errors.push_back("No member " + node->identifierString +
                             " in type " + firstOperand->toString());
            node->exprType = new TypeNode(new JvmDataType());;
            return node->exprType;
        }
        node->actualField = foundProp;
        node->exprType = foundProp->propertyAndReturnType;
        return node->exprType;
    }

    if (node->type == ExpressionNode::Type::_ASSIGN ||
        node->type == ExpressionNode::Type::_ASSIGN_TO_ARRAY_ELEMENT ||
        node->type == ExpressionNode::Type::_ASSIGN_TO_FIELD)
    {
        auto *firstOperand = calculateTypeForExpr(node->firstOperand);
        auto *secondOperand = calculateTypeForExpr(node->secondOperand);
        auto *thirdOperand = calculateTypeForExpr(node->thirdOperand);

        if (node->type == ExpressionNode::Type::_ASSIGN_TO_ARRAY_ELEMENT)
        {
            if (secondOperand->jvmType->arrayArity != 0 ||
                (*secondOperand->jvmType != RTL_NUMBER_TYPE ||
                 *secondOperand->jvmType !=
                     JvmDataType(JvmDataType::Type::Int)))
            {
                errors.push_back("Array index must be type int, not " +
                                 secondOperand->toString());
            }
            // node->jvmType->arrayArity -= 1;
        }

        if (node->type == ExpressionNode::Type::_ASSIGN_TO_ARRAY_ELEMENT)
        {
            secondOperand = thirdOperand;
        }
        if (node->type == ExpressionNode::Type::_ASSIGN_TO_FIELD)
        {
            firstOperand = node->actualField->propertyAndReturnType;
        }

        if (*firstOperand != *secondOperand)
        {
            if (*firstOperand->jvmType == RTL_ANY_TYPE)
            {
                firstOperand->jvmType = secondOperand->jvmType;
            }
        }

        if (node->type == ExpressionNode::Type::_ASSIGN)
        {
            const auto noVariable = !node->firstOperand->actualVar;
            const auto noField = !node->firstOperand->actualField;
            if (noField && noVariable)
                errors.push_back("Cannot assign");
        }

        node->exprType = secondOperand;
        return node->exprType;
    }

    if (node->isBinary())
    {
        auto *leftType = calculateTypeForExpr(node->firstOperand);
        auto *rightType = calculateTypeForExpr(node->secondOperand);

        if (leftType->jvmType->type == JvmDataType::Type::Complex ||
            rightType->jvmType->type == JvmDataType::Type::Complex)
        {
            errors.push_back(
                "Operator overloading is not supported in this version.");
            return node->exprType;
        }

        if (node->isLogical())
        {
            type = new TypeNode(new JvmDataType(JvmDataType::Type::Bool));
            node->exprType = type;

            if (*leftType == *type || *rightType == *type)
                return type;
        }
        if (node->isComparsion())
        {
            type = new TypeNode(new JvmDataType(JvmDataType::Type::Bool));
            node->exprType = type;

            if (*leftType == *rightType)
                return type;
        }
        else if (*leftType == *rightType)
        {
            type = leftType;
            node->exprType = type;

            // if (node->type != ExpressionNode::Type::_PLUS ||
            // (leftType->jvmParamType == ))
            // {
            //     errors.push_back(
            //         "The operands of arithmetic operation must be of "
            //         "type 'number'.");
            // } else {

            // }
            return type;
        }

        if (node->type == ExpressionNode::Type::_COMMA)
        {
            type = rightType;
            node->exprType = type;
            return type;
        }

        errors.push_back("Types '" + leftType->toString() + "' and '" +
                         rightType->toString() +
                         "' are not compatible with operation " +
                         node->toStringType());
    }
    if (node->isUnary())
    {
        auto *leftType = calculateTypeForExpr(node->firstOperand);
        type = leftType;
        node->exprType = type;

        if (leftType->jvmType->type == JvmDataType::Type::Complex)
        {
            errors.push_back(
                "Operator overloading is not supported in this version.");
            type = new TypeNode(new JvmDataType(RTL_ANY_TYPE));
            node->exprType = type;
            return type;
        }

        if (node->type == ExpressionNode::Type::_POST_DECREMENT ||
            node->type == ExpressionNode::Type::_POST_INCREMENT ||
            node->type == ExpressionNode::Type::_PREF_DECREMENT ||
            node->type == ExpressionNode::Type::_PREF_INCREMENT)
        {
            if (node->firstOperand->type != ExpressionNode::Type::_IDENTIFIER ||
                node->firstOperand->type !=
                    ExpressionNode::Type::_ARRAY_ACCESS ||
                node->firstOperand->type != ExpressionNode::Type::_FIELD_ACCESS)
            {
                errors.push_back(
                    "The operand of an increment or decrement operator must be "
                    "a variable or a property access.");
            }
        }

        if (node->type == ExpressionNode::Type::_UPLUS ||
            node->type == ExpressionNode::Type::_UMINUS)
        {
            if (*node->firstOperand->exprType->jvmType !=
                JvmDataType(JvmDataType::Type::Int))
            {
                errors.push_back("Type '" + node->exprType->toString() +
                                 "' is not compatible with operation " +
                                 node->toStringType());
            }
        }

        if (node->isLogical() && *node->firstOperand->exprType->jvmType !=
                                     JvmDataType(JvmDataType::Type::Bool))
        {
            type = new TypeNode(new JvmDataType(JvmDataType::Type::Bool));
            node->exprType = type;
            errors.push_back(
                "Type '" + node->firstOperand->exprType->toString() +
                "' is not compatible with operation " + node->toStringType());
        }
        return type;
    }

    if (node->type == ExpressionNode::Type::_TERNARY)
    {
        calculateTypeForExpr(node->firstOperand);
        calculateTypeForExpr(node->secondOperand);
        calculateTypeForExpr(node->thirdOperand);

        if (*node->firstOperand->exprType->jvmType !=
                JvmDataType(JvmDataType::Type::Bool) ||
            *node->firstOperand->exprType->jvmType !=
                JvmDataType(RTL_BOOLEAN_TYPE))
        {
            errors.push_back(
                "Ternary condition must be boolean type in this version.");
        }
    }
    type = new TypeNode(new JvmDataType());
    node->exprType = type;
    return type;
}

ExpressionNode *ClassAnalyzer::replaceAssignmentsOnArrayElements(
    ExpressionNode *node)
{
    auto *converted = node->toASsignOnArrayElement();
    if (converted)
        return converted;
    return node;
}

ExpressionNode *ClassAnalyzer::replaceAssignmentsOnField(ExpressionNode *node)
{
    auto *converted = node->toAssignOnField();
    if (converted)
        return converted;
    return node;
}

void ClassAnalyzer::validateTypename(JvmDataType *jvmDataType)
{
    if (!jvmDataType || jvmDataType->type != JvmDataType::Type::Complex)
        return;

    const auto foundClass =
        std::find_if(root->classes.begin(), root->classes.end(),
                     [&](ClassDeclarationNode *class_)
                     { return class_->className == jvmDataType->complex; });

    if (foundClass == root->classes.end())
    {
        errors.push_back("Cannot find name '" + jvmDataType->complex + "'");
        return;
    }
}

ClassDeclarationNode *ClassAnalyzer::findClass(JvmDataType *jvmDataType) const
{
    if (!jvmDataType || jvmDataType->type != JvmDataType::Type::Complex)
        return nullptr;

    if (jvmDataType->arrayArity > 0)
        return nullptr;

    return root->findClass(jvmDataType->complex);
}
