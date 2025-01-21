#include "class_analyzer.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

#include "commands.h"
using namespace std::string_literals;

bool operator==(const Constant &lhs, const Constant &rhs)
{
    if (lhs.Type != rhs.Type)
    {
        return false;
    }
    switch (lhs.Type)
    {
    case Constant::TypeT::Utf8:
        return lhs.Utf8 == rhs.Utf8;
    case Constant::TypeT::Integer:
        return lhs.Integer == rhs.Integer;
    case Constant::TypeT::Double:
        return lhs.Double == rhs.Double;
    case Constant::TypeT::String:
        return lhs.Utf8Id == rhs.Utf8Id;
    case Constant::TypeT::Class:
        return lhs.ClassNameId == rhs.ClassNameId;
    case Constant::TypeT::NameAndType:
        return lhs.NameId == rhs.NameId && lhs.TypeId == rhs.TypeId;
    case Constant::TypeT::MethodRef:
    case Constant::TypeT::FieldRef:
        return lhs.NameAndTypeId == rhs.NameAndTypeId &&
               lhs.ClassId == rhs.ClassId;
    }
    return false;
}

Constant Constant::CreateUtf8(std::string const &content)
{
    Constant constant;
    constant.Type = TypeT::Utf8;
    constant.Utf8 = content;
    return constant;
}

Constant Constant::CreateInt(IntT i)
{
    Constant constant;
    constant.Type = TypeT::Integer;
    constant.Integer = i;
    return constant;
}
Constant Constant::CreateEmpty()
{
    Constant constant;
    constant.Type = TypeT::Empty;
    return constant;
}

Constant Constant::CreateDouble(DoubleT double_)
{
    Constant constant;
    constant.Type = TypeT::Double;
    constant.Double = double_;
    return constant;
}

Constant Constant::CreateString(IdT Utf8)
{
    Constant constant;
    constant.Type = TypeT::String;
    constant.Utf8Id = Utf8;
    return constant;
}

Constant Constant::CreateNaT(IdT nameId, IdT typeId)
{
    Constant constant;
    constant.Type = TypeT::NameAndType;
    constant.NameId = nameId;
    constant.TypeId = typeId;
    return constant;
}

Constant Constant::CreateClass(IdT classNameId)
{
    Constant constant;
    constant.Type = TypeT::Class;
    constant.ClassNameId = classNameId;
    return constant;
}

Constant Constant::CreateFieldRef(IdT natId, IdT classId)
{
    Constant constant;
    constant.Type = TypeT::FieldRef;
    constant.NameAndTypeId = natId;
    constant.ClassId = classId;
    return constant;
}

Constant Constant::CreateMethodRef(IdT natId, IdT classId)
{
    Constant constant;
    constant.Type = TypeT::MethodRef;
    constant.NameAndTypeId = natId;
    constant.ClassId = classId;
    return constant;
}

IdT ConstantTable::FindUtf8(std::string utf8)
{
    const auto constant = Constant::CreateUtf8(std::string{utf8});
    const auto foundIter =
        std::find(Constants.begin(), Constants.end(), constant);
    if (foundIter == Constants.end())
    {
        Constants.push_back(constant);
        return Constants.end() - Constants.begin();
    }
    return foundIter - Constants.begin() + 1;
}

IdT ConstantTable::FindString(std::string str)
{
    const auto constant = Constant::CreateString(FindUtf8(str));
    const auto foundIter =
        std::find(Constants.begin(), Constants.end(), constant);
    if (foundIter == Constants.end())
    {
        Constants.push_back(constant);
        return Constants.end() - Constants.begin();
    }
    return foundIter - Constants.begin() + 1;
}

IdT ConstantTable::FindInt(IntT i)
{
    const auto constant = Constant::CreateInt(i);
    const auto foundIter =
        std::find(Constants.begin(), Constants.end(), constant);
    if (foundIter == Constants.end())
    {
        Constants.push_back(constant);
        return Constants.end() - Constants.begin();
    }
    return foundIter - Constants.begin() + 1;
}

IdT ConstantTable::FindDouble(DoubleT i)
{
    const auto constant = Constant::CreateDouble(i);
    const auto foundIter =
        std::find(Constants.begin(), Constants.end(), constant);
    if (foundIter == Constants.end())
    {
        Constants.push_back(constant);
        Constants.push_back(Constant::CreateEmpty());
        return Constants.end() - Constants.begin() - 1;
    }
    return foundIter - Constants.begin() + 1;
}

IdT ConstantTable::FindClass(std::string className)
{
    const auto constant = Constant::CreateClass(FindUtf8(className));
    const auto foundIter =
        std::find(Constants.begin(), Constants.end(), constant);
    if (foundIter == Constants.end())
    {
        Constants.push_back(constant);
        return Constants.end() - Constants.begin();
    }
    return foundIter - Constants.begin() + 1;
}

IdT ConstantTable::FindNaT(std::string name, std::string type)
{
    const auto constant = Constant::CreateNaT(FindUtf8(name), FindUtf8(type));
    const auto foundIter =
        std::find(Constants.begin(), Constants.end(), constant);
    if (foundIter == Constants.end())
    {
        Constants.push_back(constant);
        return Constants.end() - Constants.begin();
    }
    return foundIter - Constants.begin() + 1;
}

IdT ConstantTable::FindFieldRef(std::string className, std::string name,
                                std::string type)
{
    const auto constant =
        Constant::CreateFieldRef(FindNaT(name, type), FindClass(className));
    const auto foundIter =
        std::find(Constants.begin(), Constants.end(), constant);
    if (foundIter == Constants.end())
    {
        Constants.push_back(constant);
        return Constants.end() - Constants.begin();
    }
    return foundIter - Constants.begin() + 1;
}

IdT ConstantTable::FindMethodRef(std::string className, std::string name,
                                 std::string type)
{
    const auto constant =
        Constant::CreateMethodRef(FindNaT(name, type), FindClass(className));
    const auto foundIter =
        std::find(Constants.begin(), Constants.end(), constant);
    if (foundIter == Constants.end())
    {
        Constants.push_back(constant);
        return Constants.end() - Constants.begin();
    }
    return foundIter - Constants.begin() + 1;
}

void ClassAnalyzer::attributeClass(ClassDeclarationNode *node)
{
    currentClass = node;

    if (currentClass->className.starts_with("JavaRTL"))
        return;

    currentClass->thisProp = new ClassElementNode(
        "this", new TypeNode(currentClass->toDataType()), nullptr);

    if (auto parent = root->findClass(currentClass->heritageName); parent)
    {
        currentClass->superProp = new ClassElementNode(
            "super", new TypeNode(parent->toDataType()), nullptr);
    }

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

        method->elemClass = currentClass;
        currentMethod = method;

        auto *type = toJvmDataType(method->propertyAndReturnType);

        if ((*type == RTL_ANY_TYPE && method->isConstructor()) ||
            method->isMainMethod)
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
    varDecl->isAssigned = true;

    currentMethod->variables.push_back(varDecl);
    varDecl->positionInMethod = currentMethod->variables.size() - 1;
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

        if (field->expression)
        {
            if (*field->propertyAndReturnType != *field->expression->exprType)
            {
                errors.push_back(
                    "Type '" + field->expression->exprType->toString() +
                    "' is not assignable to type '" +
                    field->propertyAndReturnType->toString() + "'.");
                continue;
            }
            field->propertyAndReturnType = field->expression->exprType;
        }

        if (field->baseNode && field->baseNode->initExpression)
        {
            auto backup = errors;
            auto expr = analyzeExpr(field->baseNode->initExpression);
            errors = backup;

            if (*field->propertyAndReturnType != *expr->exprType)
            {
                errors.push_back("Type '" + expr->exprType->toString() +
                                 "' is not assignable to type '" +
                                 field->propertyAndReturnType->toString() +
                                 "'.");
                continue;
            }
            field->propertyAndReturnType = expr->exprType;
        }
        validateTypename(field->propertyAndReturnType->jvmType);
    }
    currentField = nullptr;
}

void ClassAnalyzer::analyzeClassMethod(ClassElementNode *node)
{
    node->elemClass = currentClass;
    currentMethod = node;

    currentScopingLevel = 1;

    const auto &allMethods = currentClass->body->GetMethods();
    const auto sameMethodsCount = std::count_if(
        allMethods.begin(), allMethods.end(), [&](ClassElementNode *otherMethod)
        { return node->name == otherMethod->name; });

    if (sameMethodsCount > 1)
    {
        errors.push_back("Duplicate function '" + node->name +
                         "'implementation.");
    }

    if (!currentMethod->isStatic)
    {
        currentMethod->variables.push_back(new VarDeclarationNode(
            currentClass->thisProp->name,
            currentClass->thisProp->propertyAndReturnType, nullptr));
    }

    if (!currentMethod->isMainMethod)
        moveFunctionScopedVarsOnTop();

    if (!isUnknown(currentMethod->propertyAndReturnType) &&
        currentMethod->methodBody->isEmpty())
    {
        errors.push_back(
            "A function whose declared type is neither 'undefined', 'void', "
            "nor 'any' must return a value.");
        currentMethod = nullptr;
        return;
    }
    if (!currentMethod->methodBody->isEmpty())
    {
        auto *lastStmt = currentMethod->methodBody->GetSeq().back();
        if (lastStmt->type != StatementNode::Type::_RETURN &&
            !isUnknown(currentMethod->propertyAndReturnType))
        {
            errors.push_back(
                "Function '" + currentMethod->name +
                "' lacks ending return statement and return type does "
                "not include 'undefined'.");
        }
    }
    if (isUnknown(currentMethod->propertyAndReturnType) &&
        !currentMethod->isMainMethod)
    {
        auto defaultReturn = StatementNode::fromReturnStmt(nullptr);
        currentMethod->methodBody->add(defaultReturn);
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
            currentField = nullptr;

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

    if (node->type == StatementNode::Type::_BLOCK)
    {
        incrementScopingLevel();

        auto body = new StatementListNode();
        for (auto *stmt : node->stmtList->GetSeq())
        {
            analyzeStmt(stmt, body);
        }
        node->stmtList = body;

        decrementScopingLevel();

        newSeq->add(node);
    }

    if (node->type == StatementNode::Type::_IFELSE)
    {
        analyzeIf(node);
        newSeq->add(node);
    }

    if (node->type == StatementNode::Type::_WHILE ||
        node->type == StatementNode::Type::_DOWHILE)
    {
        analyzeWhileDoWhile(node);
        newSeq->add(node);
    }
    if (node->type == StatementNode::Type::_FOR)
    {
        analyzeFor(node, newSeq);
        newSeq->add(node);
    }

    if (node->type == StatementNode::Type::_RETURN)
    {
        analyzeReturn(node);
        newSeq->add(node);
    }
}

void ClassAnalyzer::analyzeReturn(StatementNode *node)
{
    if (!node || node->type != StatementNode::Type::_RETURN)
        return;

    if (!node->expression)
    {
        node->expression = ExpressionNode::fromUndefinedLit();
    }

    node->expression = analyzeExpr(node->expression);

    if (*currentMethod->propertyAndReturnType != *node->expression->exprType)
    {
        errors.push_back("Type '" + node->expression->exprType->toString() +
                         "' is not assignable to type '" +
                         currentMethod->propertyAndReturnType->toString() +
                         "'.");
    }
}

void ClassAnalyzer::analyzeFor(StatementNode *node, StatementListNode *newSeq)
{
    if (!node || node->type != StatementNode::Type::_FOR)
        return;

    incrementScopingLevel();

    if (node->declList)
    {
        auto newList = new VarDeclarationListNode();

        for (auto varDecl : node->declList->GetSeq())
        {
            auto newNode = analyzeVarDeclaration(varDecl);
            currentField = nullptr;

            if (newNode)
                newSeq->add(newNode);
            else
                newList->add(varDecl);
        }
        if (!newList->isEmpty())
            newSeq->add(
                StatementNode::fromVarStmt(node->modifierType, newList));

        node->declList = nullptr;
    }

    node->iterationExprAdd1 = ExpressionNode::fromMethodCall(
        ExpressionNode::fromNew(
            "Boolean", new ExpressionListNode(node->iterationExprAdd1)),
        "getValue", ExpressionListNode::makeEmpty());

    node->expression = analyzeExpr(node->expression);
    node->iterationExprAdd1 = analyzeExpr(node->iterationExprAdd1);
    node->iterationExprAdd2 = analyzeExpr(node->iterationExprAdd2);
    analyzeStmt(node->iterationBody);

    decrementScopingLevel();
}

void ClassAnalyzer::analyzeWhileDoWhile(StatementNode *node)
{
    if (!node || (node->type != StatementNode::Type::_WHILE &&
                  node->type != StatementNode::Type::_DOWHILE))
        return;

    incrementScopingLevel();

    node->expression = ExpressionNode::fromMethodCall(
        ExpressionNode::fromNew("Boolean",
                                new ExpressionListNode(node->expression)),
        "getValue", ExpressionListNode::makeEmpty());

    if (node->type == StatementNode::Type::_DOWHILE)
    {
        analyzeStmt(node->iterationBody);
        node->expression = analyzeExpr(node->expression);
    }
    else
    {
        node->expression = analyzeExpr(node->expression);
        analyzeStmt(node->iterationBody);
    }

    decrementScopingLevel();
}

void ClassAnalyzer::analyzeIf(StatementNode *node)
{
    if (!node || node->type != StatementNode::Type::_IFELSE)
        return;

    incrementScopingLevel();

    node->expression = ExpressionNode::fromMethodCall(
        ExpressionNode::fromNew("Boolean",
                                new ExpressionListNode(node->expression)),
        "getValue", ExpressionListNode::makeEmpty());

    node->expression = analyzeExpr(node->expression);
    analyzeStmt(node->ifBody);
    analyzeStmt(node->elseBody);

    decrementScopingLevel();
}

StatementNode *ClassAnalyzer::analyzeVarDeclaration(VarDeclarationNode *node)
{
    if (!node)
        return nullptr;

    auto field = root->mainClass->findPropertyByName(node->identifierStr);
    if (currentMethod->isMainMethod && field &&
        (isFunctionScopeVar(node->modifierType) || currentScopingLevel == 2))
    {
        currentField = field;
    }

    node->initExpression = analyzeExpr(node->initExpression);

    node->varType->jvmType = toJvmDataType(node->varType);

    if (node->initExpression &&
        (*node->varType != *node->initExpression->exprType ||
         *node->varType->jvmType == RTL_ANY_TYPE))
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

    if (isFunctionScopeVar(node->modifierType))
    {
        auto found = currentMethod->findVariableByName(node->identifierStr,
                                                       currentScopingLevel);

        if (!found && currentMethod->isMainMethod)
        {
            auto foundProp =
                root->mainClass->body->findPropertyByName(node->identifierStr);

            if (foundProp)
                found = foundProp->baseNode;
        }

        if (found)
        {
            if (isBlockScopeVar(found->modifierType))
            {
                errors.push_back("Cannot redeclare block-scoped variable '" +
                                 node->identifierStr + "'.");
                return nullptr;
            }

            if (found->varType->toString() != node->varType->toString())
            {
                errors.push_back(
                    "Subsequent variable declarations must have the "
                    "same type. Variable '" +
                    node->identifierStr + "' must be of type '" +
                    found->varType->toString() + "', but here has type '" +
                    node->varType->toString() + "'");
                return nullptr;
            }

            node->isAssigned = true;

            auto leftExpr = ExpressionNode::fromId(node->identifierStr);
            auto rightExpr = ExpressionNode::fromId(node->identifierStr);
            if (node->initExpression)
            {
                rightExpr = node->initExpression;
            }

            auto assignReplaceNode = ExpressionNode::fromBinaryExpr(
                ExpressionNode::Type::_ASSIGN, leftExpr, rightExpr);

            assignReplaceNode = analyzeExpr(assignReplaceNode);

            if (!node->initExpression)
            {
                node->isAssigned = false;
            }

            return StatementNode::fromExprStmt(assignReplaceNode);
        }
    }
    else
    {
        auto found = currentMethod->findVariableByName(
            node->identifierStr, currentScopingLevel, currentScopingLevel);

        if (!found && currentField && currentScopingLevel == 2)
            found = currentField->baseNode;

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

        // replace for global scoped variables in main method
        if (currentMethod->isMainMethod && currentField &&
            currentScopingLevel == 2)
        {
            currentField->isPropertyAssigned = true;
            node->isAssigned = true;

            auto leftExpr = ExpressionNode::fromId(node->identifierStr);
            auto rightExpr = ExpressionNode::fromId(node->identifierStr);
            if (node->initExpression)
            {
                rightExpr = node->initExpression;
            }

            auto assignReplaceNode = ExpressionNode::fromBinaryExpr(
                ExpressionNode::Type::_ASSIGN, leftExpr, rightExpr);

            assignReplaceNode->initOfVar = node;

            assignReplaceNode = analyzeExpr(assignReplaceNode);

            if (!node->initExpression)
            {
                node->isAssigned = false;
            }

            return StatementNode::fromExprStmt(assignReplaceNode);
        }
    }

    if (node->initExpression)
        node->isAssigned = true;

    node->scopingLevel = currentScopingLevel;
    currentMethod->variables.push_back(node);
    node->positionInMethod = currentMethod->variables.size() - 1;
    return nullptr;
}

ExpressionNode *ClassAnalyzer::analyzeExpr(ExpressionNode *node)
{
    if (!node)
        return nullptr;

    auto changed = replaceOperationsOnMethodCall(node);
    changed->applyToAllChildren(replaceOperationsOnMethodCall);

    changed = replaceAssignmentsOnArrayElements(changed);
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

    const auto funcName = node->identifierString;

    if (funcName == "Number" || funcName == "String" || funcName == "Boolean")
    {
        node->type = ExpressionNode::Type::_NEW;
        return analyzeNewCall(node);
    }

    for (auto argument : node->params->GetSeq())
        argument = analyzeExpr(argument);

    node->exprType = new TypeNode(new JvmDataType(RTL_ANY_TYPE));

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

    auto const allFunctions = root->mainClass->body->GetMethods();

    ClassElementNode *foundFunc = nullptr;

    for (auto *func : allFunctions)
    {
        if (func->name == funcName && func->params->getTypes() == callTypes)
        {
            foundFunc = func;
            break;
        }
    }

    bool isAnyParamsAnyT = std::any_of(callTypes.begin(), callTypes.end(),
                                       [](JvmDataType const &type)
                                       { return type == RTL_ANY_TYPE; });

    if (!foundFunc && isAnyParamsAnyT)
    {
        for (auto *func : allFunctions)
        {
            if (func->name == funcName &&
                func->params->GetSeq().size() == callTypes.size())
            {
                foundFunc = func;
                break;
            }
        }
    }

    if (!foundFunc)
    {
        errors.push_back("Cannot call function with name '" + funcName +
                         "' with arguments of types " + toString(callTypes));
        return;
    }
    node->exprType = foundFunc->propertyAndReturnType;
    node->actualMethodCall = foundFunc;
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

        // TODO replace find_if. Compression between Any and other types is
        // buggable
        const auto foundMethod =
            std::find_if(allMethod.begin(), allMethod.end(),
                         [&](ClassElementNode *func) {
                             return methodName == func->name &&
                                    func->params->getTypes() == callTypes;
                         });

        if (foundMethod != allMethod.end())
        {
            node->exprType = (*foundMethod)->propertyAndReturnType;
            node->actualMethodCall = *foundMethod;
            break;
        }

        // XXX tries in inheritance
        if (foundClass->heritageName.empty())
        {
            foundClass = nullptr;
            break;
        }
        foundClass = root->findClass(foundClass->heritageName);
    }

    if (node->convertedFrom)
    {
        if (foundClass && *foundClass->toDataType() == RTL_ANY_TYPE &&
            (*objType->jvmType == RTL_ANY_TYPE ||
             (node->convertedFrom->secondOperand &&
              *node->convertedFrom->secondOperand->exprType->jvmType ==
                  RTL_ANY_TYPE)))
        {
            return;
        }

        if (foundClass && *foundClass->toDataType() != RTL_ANY_TYPE)
        {
            return;
        }

        if (node->convertedFrom->isBinary())
        {
            errors.push_back(
                "Types '" + objType->toString() + "' and '" +
                node->convertedFrom->secondOperand->exprType->toString() +
                "' are not compatible with operation " +
                node->convertedFrom->toStringType() + ".");
            return;
        }
        else if (node->convertedFrom->isUnary())
        {
            errors.push_back("Type '" + objType->toString() +
                             "' is not compatible with operation " +
                             node->convertedFrom->toStringType() + ".");
            return;
        }
    }

    if (foundClass)
        return;

    errors.push_back("Cannot call method " + methodName + " of " +
                     objType->toString() + " with arguments of types " +
                     toString(callTypes) + ".");
    return;
}

void ClassAnalyzer::analyzeNewCall(ExpressionNode *node)
{
    if (!node || node->type != ExpressionNode::Type::_NEW)
        return;

    for (auto argument : node->params->GetSeq())
        argument = analyzeExpr(argument);

    node->exprType = new TypeNode(new JvmDataType(RTL_ANY_TYPE));

    auto *foundClass = root->findClass(node->identifierString);

    if (!foundClass || foundClass == root->mainClass ||
        *foundClass->toDataType() == RTL_ANY_TYPE ||
        *foundClass->toDataType() == RTL_UNDEFINED_TYPE ||
        *foundClass->toDataType() == RTL_NULL_TYPE ||
        *foundClass->toDataType() == RTL_VOID_TYPE)
    {
        errors.push_back("Cannot find name '" + node->identifierString + "'");
        return;
    }

    const auto className = node->identifierString;
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
                     { return func->params->getTypes() == callTypes; });

    if (foundConstructor == allConstructors.end())
    {
        errors.push_back("Cannot call constructor of " + className +
                         " with arguments of types " + toString(callTypes));
        return;
    }
    node->exprType->jvmType = foundClass->toDataType();
    node->actualMethodCall = *foundConstructor;
}

TypeNode *ClassAnalyzer::calculateTypeForExpr(ExpressionNode *node)
{
    if (!node)
        return nullptr;

    TypeNode *type;

    if (node->type == ExpressionNode::Type::_INT_LIT)
    {
        type = new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
        node->exprType = type;
        return type;
    }
    if (node->type == ExpressionNode::Type::_FLOAT_LIT)
    {
        type = new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
        node->exprType = type;
        return type;
    }
    if (node->type == ExpressionNode::Type::_BOOLEAN_LIT)
    {
        type = new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE));
        node->exprType = type;
        return type;
    }
    if (node->type == ExpressionNode::Type::_STRING_LIT)
    {
        type = new TypeNode(new JvmDataType(RTL_STRING_TYPE));
        node->exprType = type;
        return type;
    }
    if (node->type == ExpressionNode::Type::_NULL_LIT)
    {
        type = new TypeNode(new JvmDataType(RTL_NULL_TYPE));
        node->exprType = type;
        return type;
    }
    if (node->type == ExpressionNode::Type::_UNDEFINED_LIT ||
        node->type == ExpressionNode::Type::_ARRAY_EMPTY_ELEMENT)
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
            auto elemType = elements.front()->exprType->jvmType;

            for (auto elem : elements)
            {
                if (elem->exprType->jvmType->arrayArity != 0)
                {
                    errors.push_back(
                        "Cannot create a multi-dimensional array in "
                        "this version.");
                }

                if (*elemType != *elem->exprType->jvmType)
                {
                    elemType = new JvmDataType(RTL_ANY_TYPE);
                }
            }
            node->exprType = new TypeNode(new JvmDataType(*elemType));
            node->exprType->jvmType->arrayArity++;
            node->exprType->arrayArity++;
            return node->exprType;
        }
        node->exprType = new TypeNode(new JvmDataType());
        return node->exprType;
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

        if (currentMethod)
        {
            auto *var = currentMethod->findVariableByName(
                node->identifierString, currentScopingLevel);

            if (var)
            {
                if (!var->isAssigned && !node->isLeftHand)
                {
                    errors.push_back("Variable '" + node->identifierString +
                                     "' is used before being assigned.");
                }
                type = var->varType;
                node->exprType = type;
                node->actualVar = var;
                return type;
            }
        }

        auto *var = root->mainClass->body->findPropertyByName(
            node->identifierString, currentField);

        if (var)
        {
            if (currentMethod && currentMethod->isMainMethod)
            {
                if (isBlockScopeVar(var->baseNode->modifierType) &&
                    !var->isPropertyAssigned)
                {
                    errors.push_back("Block-scoped variable '" +
                                     node->identifierString +
                                     "' used before its declaration.");
                }
                else if (!isUnknown(var->propertyAndReturnType) &&
                         !node->isLeftHand && var->baseNode &&
                         !var->baseNode->isAssigned)
                {
                    errors.push_back("Variable '" + node->identifierString +
                                     "' is used before being assigned.");
                }
            }

            type = var->propertyAndReturnType;
            node->exprType = type;
            node->actualField = var;
            return type;
        }

        // for static RTL methods
        auto *class_ = root->findClass(node->identifierString);
        if (class_)
        {
            type = new TypeNode(class_->toDataType());
            node->exprType = type;
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

        type = new TypeNode(new JvmDataType(*firstOperand->jvmType));
        type->jvmType->arrayArity = firstOperand->jvmType->arrayArity - 1;

        if (secondOperand->jvmType->arrayArity != 0 ||
            (*secondOperand->jvmType != RTL_NUMBER_TYPE &&
             *secondOperand->jvmType != JvmDataType(JvmDataType::Type::Int)))
        {
            errors.push_back("Array index must be type number, not " +
                             secondOperand->toString());
            node->exprType = type;
            return type;
        }

        if (!node->exprType)
        {
            node->secondOperand = ExpressionNode::fromMethodCall(
                node->secondOperand, "toInt", ExpressionListNode::makeEmpty());
            calculateTypeForExpr(node->secondOperand);
        }

        node->exprType = type;

        if (firstOperand->jvmType->arrayArity == 0)
        {
            errors.push_back("Cannot use operator[] on type '" +
                             type->toString() + "'.");
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

            type = new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
            node->exprType = type;
            return type;
        }
        else if (node->identifierString == "length")
        {
            node->type = ExpressionNode::Type::_METHOD_CALL;
            node->params = ExpressionListNode::makeEmpty();
            type = new TypeNode(new JvmDataType(RTL_ANY_TYPE));
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

                foundField->isPropertyAssigned = true;
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
                (*secondOperand->jvmType != RTL_NUMBER_TYPE &&
                 *secondOperand->jvmType !=
                     JvmDataType(JvmDataType::Type::Int)))
            {
                errors.push_back("Array index must be type number, not " +
                                 secondOperand->toString());
            }
            else if (!node->exprType)
            {
                node->secondOperand = ExpressionNode::fromMethodCall(
                    node->secondOperand, "toInt",
                    ExpressionListNode::makeEmpty());
                calculateTypeForExpr(node->secondOperand);
            }
        }

        if (node->type == ExpressionNode::Type::_ASSIGN_TO_ARRAY_ELEMENT)
        {
            secondOperand = thirdOperand;
            firstOperand =
                new TypeNode(new JvmDataType(*firstOperand->jvmType));
            firstOperand->jvmType->arrayArity--;
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
            node->actualField->isPropertyAssigned = true;
        }

        if (node->type == ExpressionNode::Type::_ASSIGN)
        {
            const auto noVariable = !node->firstOperand->actualVar;
            const auto noField = !node->firstOperand->actualField;
            if (noField && noVariable)
                errors.push_back("Cannot assign");
        }

        auto var = node->firstOperand->actualVar;
        if (var && var->modifierType == VarModifierType::_CONST &&
            var != node->initOfVar)
        {
            errors.push_back("Cannot assign to '" +
                             node->firstOperand->identifierString +
                             "' because it is a constant.");
        }

        auto field = node->firstOperand->actualField;
        if (field && field->baseNode &&
            field->baseNode->modifierType == VarModifierType::_CONST &&
            field->baseNode != node->initOfVar)
        {
            errors.push_back("Cannot assign to '" +
                             node->firstOperand->identifierString +
                             "' because it is a constant.");
        }

        if (var)
            var->isAssigned = true;

        if (field)
        {
            field->isPropertyAssigned = true;
            if (field->baseNode)
                field->baseNode->isAssigned = true;
        }

        node->exprType = secondOperand;
        return node->exprType;
    }

    if (node->isBinary())
    {
        auto *leftType = calculateTypeForExpr(node->firstOperand);
        auto *rightType = calculateTypeForExpr(node->secondOperand);

        if (node->type == ExpressionNode::Type::_COMMA)
        {
            type = rightType;
            node->exprType = type;
            return type;
        }

        if (leftType->jvmType->type == JvmDataType::Type::Complex ||
            rightType->jvmType->type == JvmDataType::Type::Complex)
        {
            errors.push_back(
                "Operator overloading is not supported in this version.");
            return new TypeNode(new JvmDataType());
            ;
        }

        if (node->isLogical())
        {
            type = new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE));
            node->exprType = type;

            if (*leftType == *type || *rightType == *type)
                return type;
        }
        if (node->isComparsion())
        {
            type = new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE));
            node->exprType = type;

            if (*leftType == *rightType)
                return type;
        }
        else if (*leftType == *rightType)
        {
            type = leftType;
            node->exprType = type;
            return type;
        }

        if (node->type == ExpressionNode::Type::_INSTANCEOF ||
            node->type == ExpressionNode::Type::_IN)
        {
            errors.push_back("Operator '" + node->toStringType() +
                             "' is not supported in this version.");
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

        if (node->type == ExpressionNode::Type::_POST_DECREMENT ||
            node->type == ExpressionNode::Type::_POST_INCREMENT ||
            node->type == ExpressionNode::Type::_PREF_DECREMENT ||
            node->type == ExpressionNode::Type::_PREF_INCREMENT)
        {
            if (node->firstOperand->type != ExpressionNode::Type::_IDENTIFIER &&
                node->firstOperand->type !=
                    ExpressionNode::Type::_ARRAY_ACCESS &&
                node->firstOperand->type != ExpressionNode::Type::_FIELD_ACCESS)
            {
                errors.push_back(
                    "The operand of an increment or decrement operator "
                    "must be "
                    "a variable or a property access.");
            }

            if (RTL_NUMBER_TYPE != *leftType->jvmType &&
                RTL_UNDEFINED_TYPE != *leftType->jvmType &&
                RTL_NULL_TYPE != *leftType->jvmType &&
                RTL_ANY_TYPE != *leftType->jvmType)
            {
                errors.push_back("Type '" + leftType->toString() +
                                 "' is not compatible with operation " +
                                 node->toStringType());
            }

            if (node->exprType)
                return node->exprType;

            return new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
        }

        if (leftType->jvmType->type == JvmDataType::Type::Complex)
        {
            errors.push_back(
                "Operator overloading is not supported in this version.");
            type = new TypeNode(new JvmDataType(RTL_ANY_TYPE));
            node->exprType = type;
            return type;
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
        if (!node->exprType)
        {
            node->firstOperand = ExpressionNode::fromMethodCall(
                ExpressionNode::fromNew(
                    "Boolean", new ExpressionListNode(node->firstOperand)),
                "getValue", ExpressionListNode::makeEmpty());
        }

        calculateTypeForExpr(node->firstOperand);
        calculateTypeForExpr(node->secondOperand);
        calculateTypeForExpr(node->thirdOperand);

        if (*node->secondOperand->exprType == *node->thirdOperand->exprType)
        {
            node->exprType = node->secondOperand->exprType;
            return node->exprType;
        }
    }
    type = new TypeNode(new JvmDataType());
    node->exprType = type;
    return type;
}

ExpressionNode *ClassAnalyzer::replaceAssignmentsOnArrayElements(
    ExpressionNode *node)
{
    auto *converted = node->toAssignOnArrayElement();
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

ExpressionNode *ClassAnalyzer::replaceOperationsOnMethodCall(
    ExpressionNode *node)
{
    auto *converted = node->toRTLMethodCall();
    if (converted)
    {
        converted->convertedFrom = node;
        return converted;
    }
    return node;
}

void ClassAnalyzer::validateTypename(JvmDataType *jvmDataType)
{
    if (!jvmDataType || jvmDataType->type != JvmDataType::Type::Complex)
        return;

    const auto foundClass = std::find_if(
        root->classes.begin(), root->classes.end(),
        [&](ClassDeclarationNode *class_)
        { return class_->toDataType()->complex == jvmDataType->complex; });

    if (foundClass == root->classes.end())
    {
        errors.push_back("Cannot find name '" + jvmDataType->complex.back() +
                         "'");
        return;
    }
}

ClassDeclarationNode *ClassAnalyzer::findClass(JvmDataType *jvmDataType) const
{
    if (!jvmDataType || jvmDataType->type != JvmDataType::Type::Complex)
        return nullptr;

    if (jvmDataType->arrayArity > 0)
        return nullptr;

    return root->findClass(jvmDataType->complex.back());
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

            if (!found && currentMethod->isMainMethod)
            {
                auto foundProp = root->mainClass->body->findPropertyByName(
                    existVarDecl->identifierStr);

                if (foundProp)
                    found = foundProp->baseNode;
            }

            if (found)
            {
                if (found->varType->toString() !=
                    existVarDecl->varType->toString())
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

void ClassAnalyzer::fillTables()
{
    for (auto *item : currentClass->body->GetSeq())
    {
        if (item->type == ClassElementNode::Type::_PROPERTY)
            fillFieldTables(item);
        else
            fillMethodTables(item);
    }
}

void ClassAnalyzer::fillFieldTables(ClassElementNode *node)
{
    const auto nameId = File.Constants.FindUtf8(node->name);
    const auto typeId = File.Constants.FindUtf8(
        node->propertyAndReturnType->jvmType->toDescriptor());

    auto accessFlags = AccessFlags::Public;

    if (node->isStatic)
        accessFlags = AccessFlags::Static | AccessFlags::Public;

    File.Fields.push_back({nameId, typeId, accessFlags, node});
}

void ClassAnalyzer::fillMethodTables(ClassElementNode *node)
{
    const auto nameId = File.Constants.FindUtf8(node->name);
    const auto methodDescriptor =
        node->isMainMethod ? "([Ljava/lang/String;)V" : node->toDescriptor();

    const auto typeId = File.Constants.FindUtf8(methodDescriptor);
    auto accessFlags = AccessFlags::Public;

    if (node->isStatic)
        accessFlags = AccessFlags::Static | AccessFlags::Public;

    File.Methods.push_back({nameId, typeId, accessFlags, node});
}

Bytes toBytes(const ConstantTable &constants)
{
    auto bytes = toBytes((uint16_t)(constants.Constants.size() + 1));
    for (auto const &constant : constants.Constants)
    {
        append(bytes, toBytes(constant));
    }
    return bytes;
}

Bytes toBytes(JvmField field)
{
    Bytes bytes;
    append(bytes, toBytes(static_cast<uint16_t>(field.AccessFlags)));
    append(bytes, toBytes(field.NameId));
    append(bytes, toBytes(field.TypeId));
    constexpr auto attributesCount = (uint16_t)0;
    append(bytes, toBytes(attributesCount));
    return bytes;
}

Bytes toBytes(ExpressionNode *expr, ClassFile &file)
{
    if (expr->type == ExpressionNode::Type::_INT_LIT)
    {
        Bytes bytes;

        const auto classId =
            file.Constants.FindClass(RTL_NUMBER_TYPE.toTypename());
        append(bytes, (uint8_t)Command::new_);
        append(bytes, toBytes(classId));
        append(bytes, (uint8_t)Command::dup);

        const auto intVal = expr->intValue;
        if (intVal >= -32768 && intVal <= 32767)
        {
            const auto intBytes = toBytes((IntT)intVal);
            bytes.push_back((uint8_t)Command::sipush);
            bytes.push_back(intBytes[2]);
            bytes.push_back(intBytes[3]);
        }
        else
        {
            const auto constantId = file.Constants.FindInt(intVal);
            const auto constantIdBytes = toBytes(constantId);
            append(bytes, (uint8_t)Command::ldc_w);
            append(bytes, constantIdBytes);
        }

        const auto constructorId = file.Constants.FindMethodRef(
            RTL_NUMBER_TYPE.toTypename(), "<init>", "(I)V");
        append(bytes, (uint8_t)Command::invokespecial);
        append(bytes, toBytes(constructorId));
        return bytes;
    }
    if (expr->type == ExpressionNode::Type::_FLOAT_LIT)
    {
        Bytes bytes;

        const auto classId =
            file.Constants.FindClass(RTL_NUMBER_TYPE.toTypename());
        append(bytes, (uint8_t)Command::new_);
        append(bytes, toBytes(classId));
        append(bytes, (uint8_t)Command::dup);

        const auto floatLiteralId = file.Constants.FindDouble(expr->floatValue);
        const auto constantIdBytes = toBytes(floatLiteralId);
        append(bytes, (uint8_t)Command::ldc2_w);
        append(bytes, constantIdBytes);

        const auto constructorId = file.Constants.FindMethodRef(
            RTL_NUMBER_TYPE.toTypename(), "<init>", "(D)V");
        append(bytes, (uint8_t)Command::invokespecial);
        append(bytes, toBytes(constructorId));
        return bytes;
    }
    if (expr->type == ExpressionNode::Type::_STRING_LIT)
    {
        Bytes bytes;

        const auto classId =
            file.Constants.FindClass(RTL_STRING_TYPE.toTypename());
        append(bytes, (uint8_t)Command::new_);
        append(bytes, toBytes(classId));
        append(bytes, (uint8_t)Command::dup);

        const auto stringLiteralId =
            file.Constants.FindString(expr->stringValue);
        append(bytes, (uint8_t)Command::ldc_w);
        append(bytes, toBytes(stringLiteralId));

        const auto constructorId = file.Constants.FindMethodRef(
            RTL_STRING_TYPE.toTypename(), "<init>", "(Ljava/lang/String;)V");
        append(bytes, (uint8_t)Command::invokespecial);
        append(bytes, toBytes(constructorId));
        return bytes;
    }
    if (expr->type == ExpressionNode::Type::_BOOLEAN_LIT)
    {
        Bytes bytes;

        const auto classId =
            file.Constants.FindClass(RTL_BOOLEAN_TYPE.toTypename());
        append(bytes, (uint8_t)Command::new_);
        append(bytes, toBytes(classId));
        append(bytes, (uint8_t)Command::dup);

        if (expr->boolValue)
            append(bytes, (uint8_t)Command::iconst_1);
        else
            append(bytes, (uint8_t)Command::iconst_0);

        const auto constructorId = file.Constants.FindMethodRef(
            RTL_BOOLEAN_TYPE.toTypename(), "<init>", "(Z)V");
        append(bytes, (uint8_t)Command::invokespecial);
        append(bytes, toBytes(constructorId));
        return bytes;
    }
    if (expr->type == ExpressionNode::Type::_UNDEFINED_LIT ||
        expr->type == ExpressionNode::Type::_ARRAY_EMPTY_ELEMENT)
    {
        Bytes bytes;

        const auto classId =
            file.Constants.FindClass(RTL_UNDEFINED_TYPE.toTypename());
        append(bytes, (uint8_t)Command::new_);
        append(bytes, toBytes(classId));
        append(bytes, (uint8_t)Command::dup);

        const auto constructorId = file.Constants.FindMethodRef(
            RTL_UNDEFINED_TYPE.toTypename(), "<init>", "()V");
        append(bytes, (uint8_t)Command::invokespecial);
        append(bytes, toBytes(constructorId));
        return bytes;
    }
    if (expr->type == ExpressionNode::Type::_NULL_LIT)
    {
        Bytes bytes;

        const auto classId =
            file.Constants.FindClass(RTL_NULL_TYPE.toTypename());
        append(bytes, (uint8_t)Command::new_);
        append(bytes, toBytes(classId));
        append(bytes, (uint8_t)Command::dup);

        const auto constructorId = file.Constants.FindMethodRef(
            RTL_NULL_TYPE.toTypename(), "<init>", "()V");
        append(bytes, (uint8_t)Command::invokespecial);
        append(bytes, toBytes(constructorId));
        return bytes;
    }

    if (expr->type == ExpressionNode::Type::_ARRAY_CREATION)
    {
        const auto type = expr->exprType->jvmType;
        if (type->arrayArity > 1)
            throw std::runtime_error{"Cannot create multidimensional array"};

        Bytes bytes;

        const auto classId =
            file.Constants.FindClass(RTL_ARRAY_TYPE.toTypename());
        append(bytes, (uint8_t)Command::new_);
        append(bytes, toBytes(classId));
        append(bytes, (uint8_t)Command::dup);

        const auto intBytes = toBytes((IntT)expr->params->GetSeq().size());
        bytes.push_back((uint8_t)Command::sipush);
        bytes.push_back(intBytes[2]);
        bytes.push_back(intBytes[3]);

        const auto constructorId = file.Constants.FindMethodRef(
            RTL_ARRAY_TYPE.toTypename(), "<init>", "(I)V");
        append(bytes, (uint8_t)Command::invokespecial);
        append(bytes, toBytes(constructorId));

        for (size_t i = 0; i < expr->params->GetSeq().size(); ++i)
        {
            auto *elem = expr->params->GetSeq()[i];
            append(bytes, (uint8_t)Command::dup);

            const auto indexBytes = toBytes((IntT)i);
            bytes.push_back((uint8_t)Command::sipush);
            bytes.push_back(indexBytes[2]);
            bytes.push_back(indexBytes[3]);

            append(bytes, toBytes(elem, file));

            const auto methodRefConstant =
                file.Constants.FindMethodRef(RTL_ARRAY_TYPE.toTypename(), "set",
                                             "(ILJavaRTL/Any;)LJavaRTL/Any;");
            append(bytes, (uint8_t)Command::invokevirtual);
            append(bytes, toBytes(methodRefConstant));
            append(bytes, (uint8_t)Command::pop);
        }
        return bytes;
    }
    if (expr->type == ExpressionNode::Type::_ARRAY_LENGTH)
    {
        Bytes bytes;

        append(bytes, toBytes(expr->firstOperand, file));

        const auto methodRefConstant = file.Constants.FindMethodRef(
            RTL_ANY_TYPE.toTypename(), "length", "()LJavaRTL/Any;");

        append(bytes, (uint8_t)Command::invokevirtual);
        append(bytes, toBytes(methodRefConstant));

        return bytes;
    }
    if (expr->type == ExpressionNode::Type::_ARRAY_ACCESS)
    {
        Bytes bytes;
        append(bytes, toBytes(expr->firstOperand, file));
        append(bytes, toBytes(expr->secondOperand, file));

        const auto methodRefConstant = file.Constants.FindMethodRef(
            RTL_ARRAY_TYPE.toTypename(), "get", "(I)LJavaRTL/Any;");

        append(bytes, (uint8_t)Command::invokevirtual);
        append(bytes, toBytes(methodRefConstant));
        return bytes;
    }
    if (expr->type == ExpressionNode::Type::_ASSIGN_TO_ARRAY_ELEMENT)
    {
        Bytes bytes;
        append(bytes, toBytes(expr->firstOperand, file));
        append(bytes, toBytes(expr->secondOperand, file));
        append(bytes, toBytes(expr->thirdOperand, file));

        const auto methodRefConstant =
            file.Constants.FindMethodRef(RTL_ARRAY_TYPE.toTypename(), "set",
                                         "(ILJavaRTL/Any;)LJavaRTL/Any;");

        append(bytes, (uint8_t)Command::invokevirtual);
        append(bytes, toBytes(methodRefConstant));
        return bytes;
    }

    if (expr->type == ExpressionNode::Type::_IDENTIFIER)
    {
        Bytes bytes;
        if (expr->actualVar)
        {
            auto *const var = expr->actualVar;
            if (var->varType->jvmType->type == JvmDataType::Type::Int)
            {
                append(bytes, (uint8_t)Command::iload);
            }
            else
            {
                append(bytes, (uint8_t)Command::aload);
            }
            append(bytes, (uint8_t)var->positionInMethod);
            return bytes;
        }
        if (expr->actualField)
        {
            Bytes objectBytes;
            auto *const field = expr->actualField;

            if (!field->isStatic)
            {
                append(objectBytes, (uint8_t)Command::aload_0);
                append(bytes, objectBytes);
                append(bytes, (uint8_t)Command::getfield);
            }
            else
            {
                append(bytes, (uint8_t)Command::getstatic);
            }

            const auto fieldRefId = file.Constants.FindFieldRef(
                field->elemClass->toDataType()->toTypename(), field->name,
                field->propertyAndReturnType->jvmType->toDescriptor());
            append(bytes, toBytes(fieldRefId));
            return bytes;
        }
        throw std::runtime_error{"could not load " +
                                 std::string{expr->identifierString}};
    }

    if (expr->type == ExpressionNode::Type::_FIELD_ACCESS)
    {
        if (expr->actualField)
        {
            Bytes bytes;
            auto *const field = expr->actualField;

            if (field->isStatic)
                append(bytes, (uint8_t)Command::getstatic);
            else
            {
                Bytes objectBytes = toBytes(expr->firstOperand, file);
                append(bytes, objectBytes);
                append(bytes, (uint8_t)Command::getfield);
            }

            const auto fieldRefId = file.Constants.FindFieldRef(
                field->elemClass->toDataType()->toTypename(), field->name,
                field->propertyAndReturnType->jvmType->toDescriptor());
            append(bytes, toBytes(fieldRefId));
            return bytes;
        }
        return {};
    }

    if (expr->type == ExpressionNode::Type::_FUNC_CALL)
    {
        Bytes bytes;
        for (auto *arg : expr->params->GetSeq())
            append(bytes, toBytes(arg, file));

        const auto *method = expr->actualMethodCall;
        const auto methodRefConstant = file.Constants.FindMethodRef(
            method->elemClass->toDataType()->toTypename(), method->name,
            method->toDescriptor());
        append(bytes, (uint8_t)Command::invokestatic);
        append(bytes, toBytes(methodRefConstant));
        return bytes;
    }

    if (expr->type == ExpressionNode::Type::_METHOD_CALL)
    {
        Bytes bytes;

        if (!expr->actualMethodCall->isStatic)
            append(bytes, toBytes(expr->firstOperand, file));

        for (auto *arg : expr->params->GetSeq())
        {
            append(bytes, toBytes(arg, file));
        }

        const auto *method = expr->actualMethodCall;
        const auto methodRefConstant = file.Constants.FindMethodRef(
            method->elemClass->toDataType()->toTypename(), method->name,
            method->toDescriptor());

        if (method->isStatic)
            append(bytes, (uint8_t)Command::invokestatic);
        else
            append(bytes, (uint8_t)Command::invokevirtual);

        append(bytes, toBytes(methodRefConstant));

        // if (!expr->actualMethodCall->isStatic)
        // {
        //     bytes.push_back(0);
        //     bytes.push_back(0);
        // }
        return bytes;
    }

    if (expr->type == ExpressionNode::Type::_ASSIGN)
    {
        if (expr->firstOperand && expr->firstOperand->actualVar)
        {
            Bytes bytes;
            const auto rightBytes = toBytes(expr->secondOperand, file);
            append(bytes, rightBytes);
            auto *var = expr->firstOperand->actualVar;
            const auto variableNumberBytes = (uint8_t)(var->positionInMethod);
            if (var->varType->jvmType->isReferenceType())
            {
                append(bytes, (uint8_t)Command::astore);
            }
            else if (var->varType->jvmType->isPrimitiveType())
            {
                append(bytes, (uint8_t)Command::istore);
            }

            append(bytes, variableNumberBytes);

            append(bytes, toBytes(expr->firstOperand, file));
            return bytes;
        }
        if (expr->firstOperand && expr->firstOperand->actualField)
        {
            Bytes bytes;

            append(bytes, toBytes(expr->secondOperand, file));

            auto *const field = expr->firstOperand->actualField;

            append(bytes, (uint8_t)Command::putstatic);

            const auto fieldRefId = file.Constants.FindFieldRef(
                field->elemClass->toDataType()->toTypename(), field->name,
                field->propertyAndReturnType->jvmType->toDescriptor());

            append(bytes, toBytes(fieldRefId));

            append(bytes, toBytes(expr->firstOperand, file));
            return bytes;
        }
        throw std::runtime_error{"cant assign"};
    }

    if (expr->type == ExpressionNode::Type::_ASSIGN_TO_FIELD)
    {
        // TODO check if field is static. Not tested in this version,
        Bytes bytes;

        Bytes objectBytes;

        if (expr->firstOperand)
        {
            objectBytes = toBytes(expr->firstOperand, file);
        }
        else
        {
            append(objectBytes, (uint8_t)Command::aload_0);
        }

        auto *const field = expr->actualField;
        append(bytes, objectBytes);
        append(bytes, toBytes(expr->secondOperand, file));

        append(bytes, (uint8_t)Command::putfield);
        const auto fieldRefId = file.Constants.FindFieldRef(
            field->elemClass->toDataType()->toTypename(), field->name,
            field->propertyAndReturnType->jvmType->toDescriptor());
        append(bytes, toBytes(fieldRefId));

        // simple way is to place on stack value that was assigned
        append(bytes, toBytes(expr->secondOperand, file));
        return bytes;
    }

    if (expr->type == ExpressionNode::Type::_NEW)
    {
        const auto type = expr->exprType->jvmType;
        if (type->type != JvmDataType::Type::Complex && type->arrayArity > 0)
            throw std::runtime_error{"Cannot create object of type " +
                                     type->toString()};

        const auto classIdConstant =
            file.Constants.FindClass(type->toTypename());

        Bytes bytes;
        append(bytes, (uint8_t)Command::new_);
        append(bytes, toBytes(classIdConstant));
        append(bytes, (uint8_t)Command::dup);

        for (auto *arg : expr->params->GetSeq())
        {
            append(bytes, toBytes(arg, file));
        }

        const auto constructorRef = file.Constants.FindMethodRef(
            type->toTypename(), expr->actualMethodCall->name,
            expr->actualMethodCall->toDescriptor());

        append(bytes, (uint8_t)Command::invokespecial);
        append(bytes, toBytes(constructorRef));

        return bytes;
    }
    if (expr->type == ExpressionNode::Type::_COMMA)
    {
        Bytes bytes;
        const auto leftBytes = toBytes(expr->firstOperand, file);
        const auto rightBytes = toBytes(expr->secondOperand, file);
        append(bytes, leftBytes);
        append(bytes, (uint8_t)Command::pop);
        append(bytes, rightBytes);
        return bytes;
    }
    if (expr->type == ExpressionNode::Type::_TERNARY)
    {
        const auto conditionBytes = toBytes(expr->firstOperand, file);
        auto trueBranchBytes = toBytes(expr->secondOperand, file);
        const auto elseBytes = toBytes(expr->thirdOperand, file);

        Bytes bytes;
        append(bytes, conditionBytes);

        const auto trueBranchOffset = toBytes((int16_t)(elseBytes.size() + 3));
        append(trueBranchBytes, (uint8_t)Command::goto_);
        append(trueBranchBytes, trueBranchOffset);

        append(bytes, (uint8_t)Command::ifeq);
        append(bytes, toBytes((int16_t)(trueBranchBytes.size() + 3)));
        append(bytes, trueBranchBytes);
        append(bytes, elseBytes);
        append(bytes, (uint8_t)Command::nop);

        return bytes;
    }
    if (expr->type == ExpressionNode::Type::_POST_INCREMENT ||
        expr->type == ExpressionNode::Type::_POST_DECREMENT ||
        expr->type == ExpressionNode::Type::_PREF_INCREMENT ||
        expr->type == ExpressionNode::Type::_PREF_DECREMENT)
    {
        Bytes bytes;

        auto *operand = expr->firstOperand;

        ClassElementNode *field = operand->actualField;
        VarDeclarationNode *variable = operand->actualVar;

        if (operand->type == ExpressionNode::Type::_ARRAY_ACCESS)
        {
            field = operand->firstOperand->actualField;
            variable = operand->firstOperand->actualVar;
        }

        if (!field && !variable)
            throw std::runtime_error{
                "Internal error: cant find actual field or variable"};

        // create new number object
        const auto numberClassId =
            file.Constants.FindClass(RTL_NUMBER_TYPE.toTypename());
        append(bytes, (uint8_t)Command::new_);
        append(bytes, toBytes(numberClassId));
        append(bytes, (uint8_t)Command::dup);

        // load value from variable or field
        append(bytes, toBytes(operand, file));

        // init wrapper object
        const auto constructorId = file.Constants.FindMethodRef(
            RTL_NUMBER_TYPE.toTypename(), "<init>",
            "(" + RTL_ANY_TYPE.toDescriptor() + ")V");
        append(bytes, (uint8_t)Command::invokespecial);
        append(bytes, toBytes(constructorId));

        if (expr->type == ExpressionNode::Type::_POST_INCREMENT ||
            expr->type == ExpressionNode::Type::_POST_DECREMENT)
        {
            // duplicate object as a result
            append(bytes, (uint8_t)Command::dup);
        }

        // argument for plus method
        append(bytes, (uint8_t)Command::new_);
        append(bytes, toBytes(numberClassId));
        append(bytes, (uint8_t)Command::dup);

        const auto intVal =
            (expr->type == ExpressionNode::Type::_POST_INCREMENT ||
             expr->type == ExpressionNode::Type::_PREF_INCREMENT)
                ? 1
                : -1;

        const auto intBytes = toBytes((IntT)intVal);
        bytes.push_back((uint8_t)Command::sipush);
        bytes.push_back(intBytes[2]);
        bytes.push_back(intBytes[3]);

        const auto intConstuctorId = file.Constants.FindMethodRef(
            RTL_NUMBER_TYPE.toTypename(), "<init>", "(I)V");
        append(bytes, (uint8_t)Command::invokespecial);
        append(bytes, toBytes(intConstuctorId));

        const auto methodRefConstant = file.Constants.FindMethodRef(
            RTL_NUMBER_TYPE.toTypename(), "plus",
            "(" + RTL_NUMBER_TYPE.toDescriptor() + ")" +
                RTL_NUMBER_TYPE.toDescriptor());

        append(bytes, (uint8_t)Command::invokevirtual);
        append(bytes, toBytes(methodRefConstant));

        if (expr->type == ExpressionNode::Type::_PREF_INCREMENT ||
            expr->type == ExpressionNode::Type::_PREF_DECREMENT)
        {
            // duplicate object as a result
            append(bytes, (uint8_t)Command::dup);
        }

        if (operand->type == ExpressionNode::Type::_ARRAY_ACCESS)
        {
            append(bytes, toBytes(operand->firstOperand, file));
            append(bytes, (uint8_t)Command::swap);
            append(bytes, toBytes(operand->secondOperand, file));
            append(bytes, (uint8_t)Command::swap);

            const auto methodRefConstant =
                file.Constants.FindMethodRef(RTL_ARRAY_TYPE.toTypename(), "set",
                                             "(ILJavaRTL/Any;)LJavaRTL/Any;");

            append(bytes, (uint8_t)Command::invokevirtual);
            append(bytes, toBytes(methodRefConstant));

            append(bytes, (uint8_t)Command::pop);
            return bytes;
        }

        if (field)
        {
            if (field->isStatic)
            {
                append(bytes, (uint8_t)Command::putstatic);
            }
            else
            {
                Bytes objectBytes;
                if (expr->firstOperand)
                    objectBytes = toBytes(expr->firstOperand, file);
                else
                    append(objectBytes, (uint8_t)Command::aload_0);
                append(bytes, objectBytes);
                append(bytes, toBytes(expr->secondOperand, file));
                append(bytes, (uint8_t)Command::putfield);
            }
            const auto fieldRefId = file.Constants.FindFieldRef(
                field->elemClass->toDataType()->toTypename(), field->name,
                field->propertyAndReturnType->jvmType->toDescriptor());

            append(bytes, toBytes(fieldRefId));
        }
        if (variable)
        {
            const auto variableNumberBytes =
                (uint8_t)(variable->positionInMethod);
            if (variable->varType->jvmType->isReferenceType())
            {
                append(bytes, (uint8_t)Command::astore);
            }
            else if (variable->varType->jvmType->isPrimitiveType())
            {
                append(bytes, (uint8_t)Command::istore);
            }
            append(bytes, variableNumberBytes);
        }
        return bytes;
    }
    return {};
}

Bytes toBytes(VarDeclarationNode *node, ClassFile &file)
{
    Bytes bytes;

    // Инициализация переменной
    if (node->initExpression)
    {
        append(bytes, toBytes(node->initExpression, file));
    }
    else
    {
        if (node->varType->jvmType->isPrimitiveType())
        {
            append(bytes, (uint8_t)Command::iconst_0);
        }
        else if (node->varType->jvmType->isReferenceType())
        {
            // TODO need more testing of default undefined value
            const auto classId =
                file.Constants.FindClass(RTL_UNDEFINED_TYPE.toTypename());
            append(bytes, (uint8_t)Command::new_);
            append(bytes, toBytes(classId));
            append(bytes, (uint8_t)Command::dup);

            const auto constructorId = file.Constants.FindMethodRef(
                RTL_UNDEFINED_TYPE.toTypename(), "<init>", "()V");
            append(bytes, (uint8_t)Command::invokespecial);
            append(bytes, toBytes(constructorId));
            // append(bytes, (uint8_t)Command::aconst_null);
        }
        else
        {
            throw std::runtime_error("unsupported type of variable " +
                                     node->varType->toString());
        }
    }

    if (node->varType->jvmType->isPrimitiveType())
    {
        append(bytes, (uint8_t)Command::istore);
    }
    else if (node->varType->jvmType->isReferenceType())
    {
        append(bytes, (uint8_t)Command::astore);
    }

    append(bytes, (uint8_t)node->positionInMethod);

    return bytes;
}

Bytes toBytes(StatementNode *stmt, ClassFile &file);

Bytes toBytesIfElse(StatementNode *stmt, ClassFile &file)
{
    const auto hasElse = stmt->elseBody != nullptr;
    const auto conditionBytes = toBytes(stmt->expression, file);
    auto trueBranchBytes = toBytes(stmt->ifBody, file);
    const auto elseBytes = toBytes(stmt->elseBody, file);

    Bytes bytes;
    append(bytes, conditionBytes);

    if (hasElse)
    {
        const auto trueBranchOffset = toBytes((int16_t)(elseBytes.size() + 3));
        append(trueBranchBytes, (uint8_t)Command::goto_);
        append(trueBranchBytes, trueBranchOffset);
    }

    append(bytes, (uint8_t)Command::ifeq);
    append(bytes, toBytes((int16_t)(trueBranchBytes.size() + 3)));
    append(bytes, trueBranchBytes);
    append(bytes, elseBytes);
    append(bytes, (uint8_t)Command::nop);

    return bytes;
}

Bytes toBytesWhileDoWhile(StatementNode *stmt, ClassFile &file)
{
    Bytes bytes;

    const auto conditionBytes = toBytes(stmt->expression, file);
    const auto bodyBytes = toBytes(stmt->iterationBody, file);

    constexpr auto ifeqCommandLength = 3;
    constexpr auto gotoCommandLength = 3;

    const auto gotoBytesOffset = -static_cast<int16_t>(
        conditionBytes.size() + bodyBytes.size() + ifeqCommandLength);

    const auto ifeqBytesOffset = static_cast<int16_t>(
        bodyBytes.size() + ifeqCommandLength + gotoCommandLength);

    if (stmt->type == StatementNode::Type::_DOWHILE)
        append(bytes, bodyBytes);

    append(bytes, conditionBytes);

    append(bytes, (uint8_t)Command::ifeq);
    append(bytes, toBytes(ifeqBytesOffset));

    append(bytes, bodyBytes);

    append(bytes, (uint8_t)Command::goto_);
    append(bytes, toBytes((int16_t)gotoBytesOffset));
    append(bytes, (uint8_t)Command::nop);

    return bytes;
}

Bytes toBytesFor(StatementNode *node, ClassFile &file)
{
    Bytes bytes;

    if (node->expression)
        append(bytes, toBytes(node->expression, file));

    const auto conditionBytes = toBytes(node->iterationExprAdd1, file);
    const auto iterExprBytes = toBytes(node->iterationExprAdd2, file);

    auto bodyBytes = toBytes(node->iterationBody, file);
    append(bodyBytes, iterExprBytes);

    constexpr auto ifeqCommandLength = 3;
    constexpr auto gotoCommandLength = 3;

    const auto gotoBytesOffset = -static_cast<int16_t>(
        conditionBytes.size() + bodyBytes.size() + ifeqCommandLength);

    const auto ifeqBytesOffset = static_cast<int16_t>(
        bodyBytes.size() + ifeqCommandLength + gotoCommandLength);

    append(bytes, conditionBytes);

    append(bytes, (uint8_t)Command::ifeq);
    append(bytes, toBytes(ifeqBytesOffset));

    append(bytes, bodyBytes);

    append(bytes, (uint8_t)Command::goto_);
    append(bytes, toBytes((int16_t)gotoBytesOffset));

    append(bytes, (uint8_t)Command::nop);

    return bytes;
}

Bytes toBytesReturn(StatementNode *node, ClassFile &file)
{
    Bytes bytes;

    append(bytes, toBytes(node->expression, file));
    append(bytes, (uint8_t)Command::areturn);

    return bytes;
}

Bytes toBytes(StatementNode *stmt, ClassFile &file)
{
    if (!stmt)
        return {};
    Bytes bytes;

    switch (stmt->type)
    {
    case StatementNode::Type::_EMPTY:
        return bytes;
    case StatementNode::Type::_EXPRESSION:
        return toBytes(stmt->expression, file);
    case StatementNode::Type::_VAR:
    {
        for (auto decl : stmt->declList->GetSeq())
        {
            append(bytes, toBytes(decl, file));
        }
        return bytes;
    }
    case StatementNode::Type::_BLOCK:
    {
        for (auto *blockStmt : stmt->stmtList->GetSeq())
        {
            append(bytes, toBytes(blockStmt, file));
        }
        return bytes;
    }
    case StatementNode::Type::_IFELSE:
        return toBytesIfElse(stmt, file);

    case StatementNode::Type::_WHILE:
    case StatementNode::Type::_DOWHILE:
        return toBytesWhileDoWhile(stmt, file);

    case StatementNode::Type::_FOR:
        return toBytesFor(stmt, file);

    case StatementNode::Type::_RETURN:
        return toBytesReturn(stmt, file);

    default:;
    }
    return {};
}

Bytes toBytes(ClassElementNode *method, ClassFile &classFile)
{
    Bytes bytes;

    constexpr auto stackSize = (uint16_t)1000;
    append(bytes, toBytes(stackSize));

    const uint16_t localVariablesCount = method->variables.size() + 1;

    append(bytes, toBytes(localVariablesCount));

    Bytes codeBytes;

    if (method->type == ClassElementNode::Type::_CONSTRUCTOR)
    {
        append(codeBytes, (uint8_t)Command::aload_0);
        append(codeBytes, (uint8_t)Command::invokespecial);
        const auto javaBaseObjectConstructor =
            classFile.Constants.FindMethodRef(JAVA_OBJECT_TYPE.toTypename(),
                                              "<init>", "()V");
        append(codeBytes, toBytes(javaBaseObjectConstructor));
    }

    for (auto *stmt : method->methodBody->GetSeq())
    {
        append(codeBytes, toBytes(stmt, classFile));
    }

    append(codeBytes, (uint8_t)Command::return_);

    append(bytes, toBytes((uint32_t)codeBytes.size()));
    append(bytes, codeBytes);

    constexpr auto exceptionTableSize = (uint16_t)0;
    constexpr auto attributesTableSize = (uint16_t)0;

    append(bytes, toBytes(exceptionTableSize));
    append(bytes, toBytes(attributesTableSize));

    return bytes;
}

Bytes toBytes(JvmMethod method, ClassFile &classFile)
{
    Bytes bytes;
    append(bytes, toBytes(static_cast<uint16_t>(method.AccessFlags)));
    append(bytes, toBytes(method.NameId));
    append(bytes, toBytes(method.TypeId));
    constexpr auto attributesCount = (uint16_t)1;  // The only attribute is Code
    append(bytes, toBytes(attributesCount));
    append(bytes, toBytes(classFile.Constants.FindUtf8("Code")));
    const auto codeBytes = toBytes(method.actualMethod, classFile);
    auto codeBytesLength = toBytes((uint32_t)codeBytes.size());
    append(bytes, codeBytesLength);
    append(bytes, codeBytes);
    return bytes;
}

Bytes toBytesConstantConstruct(ClassFile &classFile)
{
    Bytes bytes;
    append(bytes, toBytes(static_cast<uint16_t>(AccessFlags::Static)));
    append(bytes, toBytes(classFile.Constants.FindUtf8("<clinit>")));
    append(bytes, toBytes(classFile.Constants.FindUtf8("()V")));
    constexpr auto attributesCount = (uint16_t)1;  // The only attribute is Code
    append(bytes, toBytes(attributesCount));
    append(bytes, toBytes(classFile.Constants.FindUtf8("Code")));

    Bytes methodBytes;
    append(methodBytes, toBytes((uint16_t)1000));
    append(methodBytes, toBytes((uint16_t)0));

    Bytes codeBytes;

    for (auto field : classFile.Fields)
    {
        const auto classId =
            classFile.Constants.FindClass(RTL_UNDEFINED_TYPE.toTypename());
        append(codeBytes, (uint8_t)Command::new_);
        append(codeBytes, toBytes(classId));
        append(codeBytes, (uint8_t)Command::dup);

        const auto constructorId = classFile.Constants.FindMethodRef(
            RTL_UNDEFINED_TYPE.toTypename(), "<init>", "()V");
        append(codeBytes, (uint8_t)Command::invokespecial);
        append(codeBytes, toBytes(constructorId));

        append(codeBytes, (uint8_t)Command::putstatic);

        const auto fieldRefId = classFile.Constants.FindFieldRef(
            field.actualField->elemClass->toDataType()->toTypename(),
            field.actualField->name,
            field.actualField->propertyAndReturnType->jvmType->toDescriptor());

        append(codeBytes, toBytes(fieldRefId));
    }
    append(codeBytes, (uint8_t)Command::return_);

    append(methodBytes, toBytes((uint32_t)codeBytes.size()));
    append(methodBytes, codeBytes);

    constexpr auto exceptionTableSize = (uint16_t)0;
    constexpr auto attributesTableSize = (uint16_t)0;

    append(methodBytes, toBytes(exceptionTableSize));
    append(methodBytes, toBytes(attributesTableSize));

    append(bytes, toBytes((uint32_t)methodBytes.size()));
    append(bytes, methodBytes);
    return bytes;
}

#include <filesystem>
#include <fstream>

void ClassAnalyzer::generate()
{
    using namespace std::filesystem;
    const auto filename = std::string{currentClass->className} + ".class";
    auto filepath = current_path() / "Output" / filename;
    create_directory(current_path() / "Output");
    std::fstream out{filepath, std::ios_base::out | std::ios_base::binary |
                                   std::ios_base::trunc};
    out << (char)0xCA << (char)0xFE << (char)0xBA << (char)0xBE;
    const auto minorVersion = ::toBytes(ClassFile::MinorVersion);
    out.write((char *)minorVersion.data(), minorVersion.size());
    const auto majorVersion = ::toBytes(ClassFile::MajorVersion);
    out.write((char *)majorVersion.data(), majorVersion.size());

    auto const classBytes = this->toBytes();
    auto const constantBytes = ::toBytes(File.Constants);
    out.write((char *)constantBytes.data(), constantBytes.size());

    out.write((char *)classBytes.data(), classBytes.size());

    const auto classAttributesCount = ::toBytes((uint16_t)0);
    out.write((char *)classAttributesCount.data(), classAttributesCount.size());
}

Bytes ClassAnalyzer::toBytes()
{
    Bytes bytes;
    const auto classConstantId =
        File.Constants.FindClass(currentClass->toDataType()->toTypename());
    const auto superClassId =
        File.Constants.FindClass(JAVA_OBJECT_TYPE.toTypename());

    const auto accessFlags = AccessFlags::Super | AccessFlags::Public;
    append(bytes, ::toBytes((uint16_t)accessFlags));
    append(bytes, ::toBytes(classConstantId));
    append(bytes, ::toBytes(superClassId));

    constexpr auto interfacesCount = (uint16_t)0;
    append(bytes, ::toBytes(interfacesCount));

    append(bytes, ::toBytes((uint16_t)File.Fields.size()));
    for (auto field : File.Fields)
    {
        append(bytes, ::toBytes(field));
    }

    std::sort(File.Methods.begin(), File.Methods.end(),
              [](auto const &lhs, auto const &rhs)
              {
                  return (lhs.actualMethod->type ==
                          ClassElementNode::Type::_CONSTRUCTOR) >
                         (rhs.actualMethod->type ==
                          ClassElementNode::Type::_CONSTRUCTOR);
              });
    append(bytes, ::toBytes((uint16_t)(File.Methods.size() + 1)));

    append(bytes, toBytesConstantConstruct(File));

    for (auto method : File.Methods)
    {
        append(bytes, ::toBytes(method, File));
    }
    return bytes;
}

Bytes toBytes(const uint32_t n)
{
    const auto netNum = n;

    union
    {
        uint32_t num;
        unsigned char bytes[sizeof(uint32_t)];
    } u;

    u.num = netNum;

    Bytes bytes(sizeof(n), '\0');

    std::reverse_copy(std::begin(u.bytes), std::end(u.bytes), bytes.begin());

    return bytes;
}

Bytes toBytes(const int16_t n)
{
    Bytes bytes;
    const auto otherBytes = toBytes((int32_t)n);
    bytes.push_back(otherBytes[2]);
    bytes.push_back(otherBytes[3]);
    return bytes;
}

Bytes toBytes(const uint16_t n)
{
    const auto netNum = n;
    Bytes bytes(sizeof n, '\0');
    for (int i = 0; i < bytes.size(); i++)
        bytes[bytes.size() - 1 - i] = (netNum >> (i * 8));
    return bytes;
}

Bytes toBytes(const IntT n)
{
    const auto netNum = n;
    Bytes bytes(sizeof n, '\0');
    for (int i = 0; i < bytes.size(); i++)
        bytes[bytes.size() - 1 - i] = (netNum >> (i * 8));
    return bytes;
}

Bytes toBytes(const DoubleT n)
{
    Bytes bytes(sizeof(n), '\0');

    const unsigned char *bytePtr = reinterpret_cast<const unsigned char *>(&n);

    for (std::size_t i = 0; i < bytes.size(); ++i)
        bytes[bytes.size() - 1 - i] = bytePtr[i];

    // append(bytes, 9);
    return bytes;
}

Bytes toBytes(Constant const &constant)
{
    Bytes bytes;

    if (constant.Type == Constant::TypeT::Empty)
        return bytes;

    append(bytes, static_cast<uint8_t>(constant.Type));
    switch (constant.Type)
    {
    case Constant::TypeT::Utf8:
        append(bytes, toBytes((uint16_t)constant.Utf8.size()));
        append(bytes, constant.Utf8);
        break;
    case Constant::TypeT::Integer:
        append(bytes, toBytes(constant.Integer));
        break;
    case Constant::TypeT::Double:
        append(bytes, toBytes(constant.Double));
        break;
    case Constant::TypeT::String:
        append(bytes, toBytes(constant.Utf8Id));
        break;
    case Constant::TypeT::NameAndType:
        append(bytes, toBytes(constant.NameId));
        append(bytes, toBytes(constant.TypeId));
        break;
    case Constant::TypeT::Class:
        append(bytes, toBytes(constant.ClassNameId));
        break;
    case Constant::TypeT::MethodRef:
    case Constant::TypeT::FieldRef:
        append(bytes, toBytes(constant.ClassId));
        append(bytes, toBytes(constant.NameAndTypeId));
        break;
    default:;
    }
    return bytes;
}