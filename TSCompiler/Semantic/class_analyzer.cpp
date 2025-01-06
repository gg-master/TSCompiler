#include "class_analyzer.h"

void ClassAnalyzer::attributeClass(ClassDeclarationNode *node)
{
    currentClass = node;

    if (currentClass->className.starts_with("JavaRTL"))
        return;

    currentClass->thisProp = new ClassElementNode(
        "this", new TypeNode(currentClass->toDataType()), nullptr);

    resolveClassConstructor();
    attributeMemberSignatures();
}

void ClassAnalyzer::resolveClassConstructor()
{
    std::vector<ClassElementNode *> constructors =
        currentClass->body->GetConstructors();

    if (constructors.size() > 1)
    {
        errors.push_back(
            "Multiple constructor implementations are not allowed.");
        return;
    }

    if (!constructors.empty())
        return;

    if (currentClass->heritageName.empty())
    {
        auto constructor =
            new ClassElementNode{RequiredParameterListNode::makeEmpty(),
                                 StatementListNode::makeEmpty()};
        currentClass->body->add(constructor);
        return;
    }

    // Trying to copy parent class constructor
    auto foundParent = root->findClass(currentClass->heritageName);
    if (!foundParent)
    {
        errors.push_back("Cannot find name '" + currentClass->heritageName +
                         "'.");
        return;
    }

    auto parentClass =
        root->findClass(currentClass->heritageName, currentClass);
    if (!parentClass)
    {
        errors.push_back("Class '" + currentClass->heritageName +
                         "' used before its declaration.");
        return;
    }

    // Recursive search for a constructor in parent classes
    ClassElementNode *constructor = nullptr;
    while (parentClass)
    {
        auto constrs = parentClass->body->GetConstructors();
        if (!constrs.empty())
        {
            constructor = new ClassElementNode(constrs[0]->params,
                                               StatementListNode::makeEmpty());
            break;
        }

        if (!parentClass->heritageName.empty())
        {
            parentClass = root->findClass(parentClass->heritageName);
        }
        else
        {
            parentClass = nullptr;
        }
    }

    // If no constructor was found, create an empty one
    if (!constructor)
    {
        constructor =
            new ClassElementNode{RequiredParameterListNode::makeEmpty(),
                                 StatementListNode::makeEmpty()};
    }
    constructor->methodBody->add(
        StatementNode::fromExprStmt(ExpressionNode::fromSuperCall(
            ExpressionListNode::fromRequiredParams(constructor->params))));

    currentClass->body->add(constructor);

    errors.push_back("Inheritance is not supported in this version.");
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
    if (currentMethod->type == ClassElementNode::Type::_CONSTRUCTOR &&
        param->paramName == "this")
    {
        errors.push_back("A constructor cannot have a 'this' parameter.");
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

    const auto &allProps = currentClass->body->GetProperties();
    const auto samePropsCount = std::count_if(
        allProps.begin(), allProps.end(), [&](ClassElementNode *otherProp)
        { return node->name == otherProp->name; });

    if (samePropsCount > 1)
    {
        errors.push_back("Duplicate identifier '" + node->name + "'");
        return;
    }

    if (node->name == "this")
    {
        errors.push_back("Cannot create 'this' property of class '" +
                         currentClass->className + "' in this version.");
        return;
    }
}

void ClassAnalyzer::analyzeClass(ClassDeclarationNode *node)
{
    currentClass = node;

    if (currentClass->className.starts_with("JavaRTL"))
        return;

    analyzeClassConstructor();
    analyzeClassFields();

    for (auto *method : currentClass->body->GetMethods())
    {
        analyzeClassMethod(method);
    }
}

void ClassAnalyzer::analyzeClassConstructor()
{
    auto constructors = currentClass->body->GetConstructors();
    if (constructors.empty())
        return;

    ClassElementNode *constructor = constructors[0];

    if (!currentClass->heritageName.empty())
    {
        auto const &body = constructor->methodBody->GetSeq();
        int superCount = 0;
        bool superAtBeginning = false;

        for (size_t i = 0; i < body.size(); ++i)
        {
            if (body[i]->type == StatementNode::Type::_EXPRESSION &&
                body[i]->expression->type == ExpressionNode::Type::_SUPER_CALL)
            {
                superCount++;
                if (i == 0)
                    superAtBeginning = true;
            }
        }
        if (superCount == 0)
        {
            errors.push_back(
                "Constructors for derived classes must contain a 'super' "
                "call.");
        }
        else if (superCount > 1)
        {
            errors.push_back(
                "Multiple super call is not supported in this version.");
        }
        else if (!superAtBeginning)
        {
            errors.push_back(
                "A 'super' call must be the first statement in the "
                "constructor.");
        }
    }

    constructor->elemClass = currentClass;
    currentMethod = constructor;

    currentScopingLevel = 1;

    if (auto parent = root->findClass(currentClass->heritageName); parent)
    {
        auto *superVar = new VarDeclarationNode(
            "super", new TypeNode(parent->toDataType()), nullptr);
        currentMethod->variables.push_back(superVar);
    }

    moveFunctionScopedVarsOnTop();

    incrementScopingLevel();

    for (auto *stmt : currentMethod->methodBody->GetSeq())
    {
        analyzeStmt(stmt);
    }
    decrementScopingLevel();

    // move to return stmt
    if (!currentMethod->methodBody->isEmpty())
    {
        auto *lastStmt = currentMethod->methodBody->GetSeq().back();
        if (lastStmt->type == StatementNode::Type::_RETURN &&
            *lastStmt->expression->exprType !=
                *currentClass->thisProp->propertyAndReturnType)
        {
            errors.push_back(
                "Return type of constructor signature must be assignable to "
                "the instance type of the class.");
        }
    }

    currentMethod = nullptr;
}

void ClassAnalyzer::analyzeClassFields()
{
    for (auto *field : currentClass->body->GetProperties())
    {
        currentField = field;

        if (!isUnknown(field->propertyAndReturnType) && !field->expression &&
            !field->initInConstructor && currentClass != root->mainClass)
        {
            errors.push_back("Property '" + field->name +
                             "' has no initializer and is not definitely "
                             "assigned in the constructor.");
            continue;
        }
        field->expression = analyzeExpr(field->expression);
    }
    currentField = nullptr;
}

void ClassAnalyzer::analyzeClassMethod(ClassElementNode *node)
{
    node->elemClass = currentClass;
    currentMethod = node;

    currentScopingLevel = 1;

    if (auto parent = root->findClass(currentClass->heritageName); parent)
    {
        auto *superVar = new VarDeclarationNode(
            "super", new TypeNode(parent->toDataType()), nullptr);
        currentMethod->variables.push_back(superVar);
    }

    const auto &allMethods = currentClass->body->GetMethods();
    const auto sameMethodsCount = std::count_if(
        allMethods.begin(), allMethods.end(), [&](ClassElementNode *otherMethod)
        { return node->name == otherMethod->name; });

    if (sameMethodsCount > 1)
    {
        errors.push_back("Duplicate function '" + node->name +
                         "'implementation.");
    }

    if (!currentMethod->name.starts_with(root->mainClass->className))
        moveFunctionScopedVarsOnTop();

    // todo add last stmt return of undefined
    if (!isUnknown(currentMethod->propertyAndReturnType) &&
        currentMethod->methodBody->isEmpty())
    {
        errors.push_back(
            "A function whose declared type is neither 'undefined', 'void', "
            "nor 'any' must return a value.");
        currentMethod = nullptr;
        return;
    }

    incrementScopingLevel();

    auto newMethodBody = new StatementListNode();
    for (auto *stmt : currentMethod->methodBody->GetSeq())
    {
        analyzeStmt(stmt, newMethodBody);
    }
    currentMethod->methodBody = newMethodBody;

    decrementScopingLevel();

    if (currentClass == root->mainClass)
    {
        currentMethod = nullptr;
        return;
    }

    if (!currentMethod->methodBody->isEmpty())
    {
        auto *lastStmt = currentMethod->methodBody->GetSeq().back();
        if (lastStmt->type != StatementNode::Type::_RETURN &&
            !isUnknown(currentMethod->propertyAndReturnType))
        {
            errors.push_back("Last statement in method " + currentMethod->name +
                             " must be return!");
        }
        else if (lastStmt->type != StatementNode::Type::_RETURN)
        {
            // TODO add last statement return of undefined
            // currentMethod
        }
    }

    currentMethod = nullptr;
}

void ClassAnalyzer::analyzeStmt(StatementNode *node, StatementListNode *newSeq)
{
    if (!node)
        return;

    if (!newSeq)
        newSeq = new StatementListNode();

    if (node->type == StatementNode::Type::_VAR)
    {
        auto newList = new VarDeclarationListNode();

        for (auto varDecl : node->declList->GetSeq())
        {
            auto newNode = analyzeVarDeclaration(varDecl);
            if (newNode)
                newSeq->add(newNode);
            else
                newList->add(varDecl);
        }
        if (!newList->isEmpty())
            newSeq->add(
                StatementNode::fromVarStmt(node->modifierType, newList));
    }

    if (node->type == StatementNode::Type::_EXPRESSION)
    {
        node->expression = analyzeExpr(node->expression);
        newSeq->add(node);
    }
}

StatementNode *ClassAnalyzer::analyzeVarDeclaration(VarDeclarationNode *node)
{
    if (!node)
        return nullptr;

    auto field = root->mainClass->body->findPropertyByName(node->identifierStr);
    if (currentMethod->isMainMethod && field)
    {
        currentField = field;
    }

    node->initExpression = analyzeExpr(node->initExpression);

    node->varType->jvmType = toJvmDataType(node->varType);

    if (node->initExpression &&
        *node->varType != *node->initExpression->exprType)
    {
        if (*node->varType->jvmType != RTL_ANY_TYPE)
        {
            errors.push_back("Type '" +
                             node->initExpression->exprType->toString() +
                             "' is not assignable to type '" +
                             node->varType->toString() + "'.");
        }
        else
        {
            node->varType = node->initExpression->exprType;
        }
    }

    validateTypename(node->varType->jvmType);

    if (!currentMethod)
        return nullptr;

    if (isFunctionScopeVar(node->modifierType))
    {
        auto found = currentMethod->findVariableByName(node->identifierStr,
                                                       currentScopingLevel);

        if (found)
        {
            if (isBlockScopeVar(found->modifierType))
            {
                errors.push_back("Cannot redeclare block-scoped variable '" +
                                 node->identifierStr + "'.");
                return nullptr;
            }

            if (*found->varType != *node->varType &&
                *found->varType->jvmType != RTL_ANY_TYPE)
            {
                errors.push_back(
                    "Subsequent variable declarations must have the "
                    "same type. Variable '" +
                    node->identifierStr + "' must be of type '" +
                    found->varType->toString() + "', but here has type '" +
                    node->varType->toString() + "'");
                return nullptr;
            }
            auto leftExpr = ExpressionNode::fromId(node->identifierStr);
            auto rightExpr = ExpressionNode::fromId(node->identifierStr);
            if (node->initExpression)
            {
                rightExpr = node->initExpression;
            }

            auto assignReplaceNode = ExpressionNode::fromBinaryExpr(
                ExpressionNode::Type::_ASSIGN, leftExpr, rightExpr);

            return StatementNode::fromExprStmt(analyzeExpr(assignReplaceNode));
        }
    }
    else
    {
        auto found = currentMethod->findVariableByName(node->identifierStr,
                                                       currentScopingLevel);

        if (found && found != node)
        {
            if (isBlockScopeVar(found->modifierType))
            {
                errors.push_back("Cannot redeclare block-scoped variable '" +
                                 node->identifierStr + "'.");
                return nullptr;
            }
            errors.push_back("Duplicate identifier '" + node->identifierStr +
                             "'.");
            return nullptr;
        }
    }
    node->scopingLevel = currentScopingLevel;
    currentMethod->variables.push_back(node);
    return nullptr;
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

void ClassAnalyzer::analyzeSuperCall(ExpressionNode *node)
{
    if (!node || node->type != ExpressionNode::Type::_SUPER_CALL)
        return;

    auto const &body = currentMethod->methodBody->GetSeq();
    auto const superCallStmt = std::find_if(
        body.begin(), body.end(),
        [&](StatementNode *stmt)
        {
            return stmt->type == StatementNode::Type::_EXPRESSION &&
                   stmt->expression->type == ExpressionNode::Type::_SUPER_CALL;
        });

    if (superCallStmt != body.end() && currentClass->heritageName.empty())
    {
        errors.push_back("'super' can only be referenced in a derived class.");
        return;
    }

    for (auto argument : node->params->GetSeq())
        argument = analyzeExpr(argument);

    node->exprType = new TypeNode(new JvmDataType(JvmDataType::Type::Void));

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

    auto const &allConstrs =
        root->findClass(currentClass->heritageName)->body->GetConstructors();
    const auto found = std::find_if(
        allConstrs.begin(), allConstrs.end(), [&](ClassElementNode *func)
        { return callTypes == func->params->getTypes(); });

    if (found == allConstrs.end())
    {
        errors.push_back("Cannot super call of '" + currentClass->heritageName +
                         "' with arguments of types " + toString(callTypes));
        return;
    }
    node->actualMethodCall = *found;
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

    auto *foundClass = findClass(objType->jvmType);

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

    while (foundClass)
    {
        auto const &allMethod = foundClass->body->GetMethods();
        const auto foundMethod =
            std::find_if(allMethod.begin(), allMethod.end(),
                         [&](ClassElementNode *func) {
                             return methodName == func->name &&
                                    callTypes == func->params->getTypes();
                         });

        if (foundMethod != allMethod.end())
        {
            node->exprType = (*foundMethod)->propertyAndReturnType;
            node->actualMethodCall = *foundMethod;
            return;
        }

        if (foundClass->heritageName.empty())
        {
            break;
        }
        foundClass = root->findClass(foundClass->heritageName);
    }
    errors.push_back("Cannot call method with name " + methodName +
                     " with arguments of types " + toString(callTypes));
    return;
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
        if (node->identifierString == "this")
        {
            type = currentClass->thisProp->propertyAndReturnType;
            node->exprType = type;
            node->actualField = currentClass->thisProp;
            return type;
        }

        if (currentMethod && !currentMethod->isMainMethod)
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

        auto beforeNode = currentField ? currentField : nullptr;

        auto *var = root->mainClass->body->findPropertyByName(
            node->identifierString, beforeNode);
        if (var)
        {
            type = var->propertyAndReturnType;
            node->exprType = type;
            node->actualField = var;
            return type;
        }

        auto found =
            root->mainClass->body->findPropertyByName(node->identifierString);

        if (found)
            errors.push_back("Variable '" + node->identifierString +
                             "' is used before being assigned.");
        else
            errors.push_back("Cannot find name '" + node->identifierString +
                             "'");

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
    if (node->type == ExpressionNode::Type::_SUPER_CALL)
    {
        if (!node->actualMethodCall)
        {
            analyzeSuperCall(node);
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

        ClassElementNode *foundField;
        while (foundClass)
        {
            foundField =
                foundClass->body->findPropertyByName(node->identifierString);

            if (foundField)
            {
                if (node->firstOperand->identifierString == "super")
                {
                    errors.push_back(
                        "Class field '" + node->identifierString +
                        "' defined by the parent class is not "
                        "accessible in the child class via super.");
                }

                if (!isUnknown(foundField->propertyAndReturnType) &&
                    !foundField->expression && !foundField->initInConstructor &&
                    !node->isLeftHand)
                {
                    errors.push_back("Property '" + foundField->name +
                                     "' is used before being assigned.");
                }

                if (currentField && !currentClass->body->findPropertyByName(
                                        node->identifierString, currentField))
                {
                    errors.push_back("Property '" + foundField->name +
                                     "' is used before its initialization.");
                }

                node->actualField = foundField;
                node->exprType = foundField->propertyAndReturnType;
                return node->exprType;
            }

            if (foundClass->heritageName.empty())
            {
                break;
            }

            foundClass = root->findClass(foundClass->heritageName);
        }

        errors.push_back("No member " + node->identifierString + " in type " +
                         firstOperand->toString());

        node->exprType = new TypeNode(new JvmDataType(RTL_ANY_TYPE));
        return node->exprType;
    }

    if (node->type == ExpressionNode::Type::_ASSIGN ||
        node->type == ExpressionNode::Type::_ASSIGN_TO_ARRAY_ELEMENT ||
        node->type == ExpressionNode::Type::_ASSIGN_TO_FIELD)
    {
        node->firstOperand->isLeftHand = true;

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
            else
            {
                errors.push_back("Type '" + secondOperand->toString() +
                                 "' is not assignable to type '" +
                                 firstOperand->toString() + "'.");
            }
        }

        if (node->type == ExpressionNode::Type::_ASSIGN_TO_FIELD &&
            currentMethod &&
            currentMethod->type == ClassElementNode::Type::_CONSTRUCTOR &&
            !isUnknown(firstOperand))
        {
            node->actualField->initInConstructor = node;
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
                    "The operand of an increment or decrement operator "
                    "must be "
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

void ClassAnalyzer::moveFunctionScopedVarsOnTop()
{
    if (!currentMethod)
        return;

    std::vector<VarDeclarationNode *> varDeclarations{};

    for (auto *stmt : currentMethod->methodBody->GetSeq())
    {
        for (auto *existVarDecl : stmt->getAllFunctionScopedVars())
        {
            auto found = currentMethod->findVariableByName(
                existVarDecl->identifierStr, currentScopingLevel);

            if (found)
            {
                if (found->varType != existVarDecl->varType)
                {
                    errors.push_back(
                        "Subsequent variable declarations must have the "
                        "same type. Variable '" +
                        existVarDecl->identifierStr + "' must be of type '" +
                        found->varType->toString() + "', but here has type '" +
                        existVarDecl->varType->toString() + "'");
                }
                continue;
            }
            // TODO change type TO RTL/Any and init with undefined;
            auto *varDecl = new VarDeclarationNode(
                existVarDecl->identifierStr, existVarDecl->varType, nullptr);

            varDecl->modifierType = existVarDecl->modifierType;
            varDecl->baseNode = existVarDecl;

            varDeclarations.push_back(varDecl);
        }
    }

    for (auto it = varDeclarations.rbegin(); it != varDeclarations.rend(); ++it)
    {
        auto stmt = StatementNode::fromVarDecl(*it);
        currentMethod->methodBody->GetSeq().insert(
            currentMethod->methodBody->GetSeq().begin(), stmt);
    }
}