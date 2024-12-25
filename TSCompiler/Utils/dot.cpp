#include <iostream>
#include <process.h>
#include <string>

#include "dot.h"

void RunDot(const std::string dotPath, const std::string dotFilePath)
{
    _spawnl(_P_NOWAIT, dotPath.data(), "dot", "-O", "-Tpng", dotFilePath.data(), NULL);
}

std::string MakeNode(const std::size_t id, const std::string name, const std::string style = "")
{
    auto res = std::to_string(id) + " [label=\"" + name + "\"]";
    if (!style.empty())
    {
        res += "[style = \"" + style + "\"]";
    }
    res += "\n";
    return res;
}

std::string MakeConnection(const size_t id1, const size_t id2, std::string note = "")
{
    auto res = std::to_string(id1) + " -> " + std::to_string(id2);

    if (!note.empty())
        res += " [label=\"" + note + "\"]";

    res += "\n";
    return res;
}

void ToDot(TypeNode *node, std::ostream &out)
{
    out << MakeNode(node->id, "TypeNode");

    std::string array_name{};
    for (int i = 0; i < node->arrayArity; ++i)
    {
        array_name += "[]";
    }

    switch (node->type)
    {
    case TypeNode::Type::_NUMBER:
        out << MakeNode(node->id, "number" + array_name);
        break;
    case TypeNode::Type::_STRING:
        out << MakeNode(node->id, "string" + array_name);
        break;
    case TypeNode::Type::_BOOLEAN:
        out << MakeNode(node->id, "boolean" + array_name);
        break;
    case TypeNode::Type::_UNDEFINED:
        out << MakeNode(node->id, "undefined" + array_name);
        break;
    case TypeNode::Type::_VOID:
        out << MakeNode(node->id, "void" + array_name);
        break;
    case TypeNode::Type::_NULL:
        out << MakeNode(node->id, "null" + array_name);
        break;
    case TypeNode::Type::_USER_TYPE:
        out << MakeNode(node->id, "UserType:\n" + std::string{node->userTypeName} + array_name);
        break;
    default:
        break;
    }
}

void ToDot(VarDeclarationNode *node, std::ostream &out)
{
    std::string name = "VarDeclarationNode\nName: " + std::string{node->identifierStr};
    out << MakeNode(node->id, name);

    if (node->varType != NULL)
    {
        ToDot(node->varType, out);
        out << MakeConnection(node->id, node->varType->id, "type");
    }

    if (node->initExpression != NULL)
    {
        ToDot(node->initExpression, out);
        out << MakeConnection(node->id, node->initExpression->id, "init");
    }
}

void ToDot(VarDeclarationListNode *node, std::ostream &out)
{
    out << MakeNode(node->id, "VarDeclarationListNode");

    if (node == NULL)
        return;

    for (const auto &child : node->GetSeq())
    {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
    }
}

void ToDot(ExpressionListNode *node, std::ostream &out)
{
    out << MakeNode(node->id, "ExpressionListNode");

    if (node == NULL)
        return;

    for (const auto &child : node->GetSeq())
    {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
    }
}

void ToDot(ExpressionNode *node, std::ostream &out)
{
    std::string name;
    switch (node->type)
    {
    case ExpressionNode::Type::_IDENTIFIER:
        out << MakeNode(node->id, "IdentName:\n" + std::string{node->identifierString});
        break;
    case ExpressionNode::Type::_INT_LIT:
        out << MakeNode(node->id, "IntLiteral:\n" + std::to_string(node->intValue));
        break;
    case ExpressionNode::Type::_FLOAT_LIT:
        out << MakeNode(node->id, "FloatLiteral:\n" + std::to_string(node->floatValue));
        break;
    case ExpressionNode::Type::_STRING_LIT:
        out << MakeNode(node->id, "StringLiteral:\n\\\"" + std::string{node->stringValue} + "\\\"");
        break;
    case ExpressionNode::Type::_BOOLEAN_LIT:
        if (node->boolValue)
        {
            name = "true";
        }
        else
        {
            name = "false";
        }
        out << MakeNode(node->id, "BooleanLiteral:\n" + name);
        break;
    case ExpressionNode::Type::_NULL_LIT:
        out << MakeNode(node->id, "NullLiteral");
        break;
    case ExpressionNode::Type::_UNDEFINED_LIT:
        out << MakeNode(node->id, "UndefinedLiteral");
        break;
    case ExpressionNode::Type::_THIS:
        out << MakeNode(node->id, "This");
        break;

    case ExpressionNode::Type::_PREF_INCREMENT:
        out << MakeNode(node->id, "PrefIncrement");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionNode::Type::_PREF_DECREMENT:
        out << MakeNode(node->id, "PrefDecrement");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionNode::Type::_POST_INCREMENT:
        out << MakeNode(node->id, "PostIncrement");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionNode::Type::_POST_DECREMENT:
        out << MakeNode(node->id, "PostDecrement");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;

    case ExpressionNode::Type::_PLUS:
        out << MakeNode(node->id, "PlusOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_MINUS:
        out << MakeNode(node->id, "MinusOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_MUL:
        out << MakeNode(node->id, "MulOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_DIV:
        out << MakeNode(node->id, "DivOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_LESS:
        out << MakeNode(node->id, "LessOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_GREAT:
        out << MakeNode(node->id, "GreatOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;

    case ExpressionNode::Type::_UPLUS:
        out << MakeNode(node->id, "UnaryPlusOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionNode::Type::_UMINUS:
        out << MakeNode(node->id, "UnaryMinusOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;

    case ExpressionNode::Type::_NOT:
        out << MakeNode(node->id, "LogicalNot");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionNode::Type::_LOGICAL_OR:
        out << MakeNode(node->id, "LogicalOr");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_LOGICAL_AND:
        out << MakeNode(node->id, "LogicalAnd");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;

    case ExpressionNode::Type::_ASSIGN:
        out << MakeNode(node->id, "Assign");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_ASSIGN_MUL:
        out << MakeNode(node->id, "AssignMul");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_ASSIGN_DIV:
        out << MakeNode(node->id, "AssignDiv");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_ASSIGN_PLUS:
        out << MakeNode(node->id, "AssignPlus");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_ASSIGN_MINUS:
        out << MakeNode(node->id, "AssignMinus");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_ASSIGN_LOGICAL_AND:
        out << MakeNode(node->id, "AssignAnd");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_ASSIGN_LOGICAL_OR:
        out << MakeNode(node->id, "AssignOr");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;

    case ExpressionNode::Type::_EQUAL:
        out << MakeNode(node->id, "Equal");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_NOT_EQUAL:
        out << MakeNode(node->id, "NotEqual");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_STRICT_EQUAL:
        out << MakeNode(node->id, "StrictEqual");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_STRICT_NOT_EQUAL:
        out << MakeNode(node->id, "StrictNotEqual");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_LESS_EQUAL:
        out << MakeNode(node->id, "LessEqual");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_GREAT_EQUAL:
        out << MakeNode(node->id, "GreaterEqual");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;

    case ExpressionNode::Type::_COMMA:
        out << MakeNode(node->id, "CommaOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_INSTANCEOF:
        out << MakeNode(node->id, "InstanceofOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_IN:
        out << MakeNode(node->id, "InOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_TERNARY:
        out << MakeNode(node->id, "Ternary");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id, "condition");
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id, "ifTrue");
        ToDot(node->thirdOperand, out);
        out << MakeConnection(node->id, node->thirdOperand->id, "ifFalse");
        break;

    case ExpressionNode::Type::_ARRAY_CREATION:
        out << MakeNode(node->id, "ArrayCreation");
        if (node->params != NULL)
        {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        break;
    case ExpressionNode::Type::_ARRAY_EMPTY_ELEMENT:
        out << MakeNode(node->id, "ArrayEmptyElement");
        break;
    case ExpressionNode::Type::_ARRAY_ACCESS:
        out << MakeNode(node->id, "ArrayAccess");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id, "array");
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id, "index");
        break;

    case ExpressionNode::Type::_FUNC_CALL:
        out << MakeNode(node->id, "FuncCall:\nFuncName: " + std::string{node->identifierString});
        if (node->params != NULL)
        {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        break;
    case ExpressionNode::Type::_SUPER_CALL:
        out << MakeNode(node->id, "SuperCall");
        if (node->params != NULL)
        {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        break;
    case ExpressionNode::Type::_FIELD_ACCESS:
        out << MakeNode(node->id,
                        "FieldAccess:\nFieldName: " + std::string{node->identifierString});
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id, "object");
        break;
    case ExpressionNode::Type::_METHOD_CALL:
        out << MakeNode(node->id,
                        "MethodAccess\nMethodName: " + std::string{node->identifierString});
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id, "object");
        if (node->params != NULL)
        {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        break;
    case ExpressionNode::Type::_NEW:
        out << MakeNode(node->id, "NewOperator:\nConstructor: " + std::string{ node->identifierString });

        if (node->params != NULL)
        {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        break;
    default:
        break;
    }
}

void ToDot(StatementNode *node, std::ostream &out)
{
    std::string name;
    switch (node->type)
    {
    case StatementNode::Type::_EMPTY:
        out << MakeNode(node->id, "EmptyStmtNode");
        break;
    case StatementNode::Type::_EXPRESSION:
        out << MakeNode(node->id, "ExprStmtNode");
        ToDot(node->expression, out);
        out << MakeConnection(node->id, node->expression->id);
        break;
    case StatementNode::Type::_VAR:
        name = "VarStmtNode\nModifierType: " + std::string{toString(node->modifierType)};
        out << MakeNode(node->id, name);

        if (node->declList != NULL)
        {
            ToDot(node->declList, out);
            out << MakeConnection(node->id, node->declList->id);
        }
        break;
    case StatementNode::Type::_RETURN:
        out << MakeNode(node->id, "ReturnStmtNode");

        if (node->expression != NULL)
        {
            ToDot(node->expression, out);
            out << MakeConnection(node->id, node->expression->id);
        }
        break;
    case StatementNode::Type::_BLOCK:
        out << MakeNode(node->id, "BlockStmtNode");

        if (node->stmtList != NULL)
        {
            ToDot(node->stmtList, out);
            out << MakeConnection(node->id, node->stmtList->id);
        }
        break;
    case StatementNode::Type::_IFELSE:
        out << MakeNode(node->id, "IfElseStmtNode");
        ToDot(node->expression, out);
        out << MakeConnection(node->id, node->expression->id, "condition");

        ToDot(node->ifBody, out);
        out << MakeConnection(node->id, node->ifBody->id, "ifBody");

        if (node->elseBody != NULL)
        {
            ToDot(node->elseBody, out);
            out << MakeConnection(node->id, node->elseBody->id, "elseBody");
        }
        break;
    case StatementNode::Type::_DOWHILE:
        out << MakeNode(node->id, "DoWhileStmtNode");
        ToDot(node->iterationBody, out);
        out << MakeConnection(node->id, node->iterationBody->id, "body");

        ToDot(node->expression, out);
        out << MakeConnection(node->id, node->expression->id, "condition");
        break;
    case StatementNode::Type::_WHILE:
        out << MakeNode(node->id, "WhileStmtNode");
        ToDot(node->iterationBody, out);
        out << MakeConnection(node->id, node->iterationBody->id, "body");

        ToDot(node->expression, out);
        out << MakeConnection(node->id, node->expression->id, "condition");
        break;
    case StatementNode::Type::_FOR:
        out << MakeNode(node->id, "ForStmtNode");
        ToDot(node->iterationBody, out);
        out << MakeConnection(node->id, node->iterationBody->id, "body");

        if (node->expression != NULL)
        {
            ToDot(node->expression, out);
            out << MakeConnection(node->id, node->expression->id, "expr");
        }

        if (node->iterationExprAdd1 != NULL)
        {
            ToDot(node->iterationExprAdd1, out);
            out << MakeConnection(node->id, node->iterationExprAdd1->id, "exprAdd1");
        }

        if (node->iterationExprAdd2 != NULL)
        {
            ToDot(node->iterationExprAdd2, out);
            out << MakeConnection(node->id, node->iterationExprAdd2->id, "exprAdd2");
        }

        if (node->declList != NULL)
        {
            ToDot(node->declList, out);
            out << MakeConnection(node->id, node->declList->id,
                                  std::string{toString(node->modifierType)});
        }

        if (node->decl != NULL)
        {
            ToDot(node->decl, out);
            out << MakeConnection(node->id, node->decl->id,
                                  std::string{toString(node->modifierType)});
        }
        break;
    default:
        break;
    }
}

void ToDot(StatementListNode *node, std::ostream &out)
{
    out << MakeNode(node->id, "StatementListNode");

    if (node == NULL)
        return;

    for (const auto &child : node->GetSeq())
    {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
    }
}

void ToDot(RequiredParameterNode *node, std::ostream &out)
{
    out << MakeNode(node->id, "RequiredParameterNode\nName: " + std::string{node->paramName});

    if (node->paramType != NULL)
    {
        ToDot(node->paramType, out);
        out << MakeConnection(node->id, node->paramType->id, "type");
    }
}

void ToDot(RequiredParameterListNode *node, std::ostream &out)
{
    out << MakeNode(node->id, "RequiredParameterListNode");

    if (node == NULL)
        return;

    for (const auto &child : node->GetSeq())
    {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
    }
}

void ToDot(FunctionDeclarationNode *node, std::ostream &out)
{
    out << MakeNode(node->id, "FunctionDeclarationNode\nName: " + std::string{node->funcName});

    if (node->params != NULL)
    {
        ToDot(node->params, out);
        out << MakeConnection(node->id, node->params->id, "params");
    }

    if (node->returnType != NULL)
    {
        ToDot(node->returnType, out);
        out << MakeConnection(node->id, node->returnType->id, "returnType");
    }

    if (node->body != NULL)
    {
        ToDot(node->body, out);
        out << MakeConnection(node->id, node->body->id, "body");
    }
}

void ToDot(ClassElementNode *node, std::ostream &out)
{
    switch (node->type)
    {
    case ClassElementNode::Type::_CONSTRUCTOR:
        out << MakeNode(node->id, "ClassConstructorNode");
        if (node->params != NULL)
        {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        if (node->methodBody != NULL)
        {
            ToDot(node->methodBody, out);
            out << MakeConnection(node->id, node->methodBody->id, "body");
        }
        break;
    case ClassElementNode::Type::_PROPERTY:
        out << MakeNode(node->id, "ClassPropertyNode\nName: " + std::string{node->name});

        if (node->propertyAndReturnType != NULL)
        {
            ToDot(node->propertyAndReturnType, out);
            out << MakeConnection(node->id, node->propertyAndReturnType->id, "type");
        }

        if (node->expression != NULL)
        {
            ToDot(node->expression, out);
            out << MakeConnection(node->id, node->expression->id, "init");
        }
        break;
    case ClassElementNode::Type::_METHOD:
        out << MakeNode(node->id, "ClassMethodNode\nName: " + std::string{node->name});
        if (node->params != NULL)
        {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }

        if (node->propertyAndReturnType != NULL)
        {
            ToDot(node->propertyAndReturnType, out);
            out << MakeConnection(node->id, node->propertyAndReturnType->id, "type");
        }

        if (node->methodBody != NULL)
        {
            ToDot(node->methodBody, out);
            out << MakeConnection(node->id, node->methodBody->id, "body");
        }
        break;
    default:
        break;
    }
}

void ToDot(ClassElementListNode *node, std::ostream &out)
{
    out << MakeNode(node->id, "ClassElementListNode");

    if (node == NULL)
        return;

    for (const auto &child : node->GetSeq())
    {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
    }
}

void ToDot(ClassDeclarationNode *node, std::ostream &out)
{
    std::string name = "ClassDeclarationNode\nName: " + std::string{node->className};
    if (!node->heritageName.empty())
    {
        name += "\\nHeritage: " + std::string{node->heritageName};
    }
    out << MakeNode(node->id, name);

    if (node->body != NULL)
    {
        ToDot(node->body, out);
        out << MakeConnection(node->id, node->body->id, "body");
    }
}

void ToDot(TSElementNode *node, std::ostream &out)
{
    out << MakeNode(node->id, "TSElementNode");

    switch (node->type)
    {
    case TSElementNode::Type::_STATEMENT:
        ToDot(node->stmt, out);
        out << MakeConnection(node->id, node->stmt->id);
        break;
    case TSElementNode::Type::_FUNCTION:
        ToDot(node->funcDecl, out);
        out << MakeConnection(node->id, node->funcDecl->id);
        break;
    case TSElementNode::Type::_CLASS:
        ToDot(node->classDecl, out);
        out << MakeConnection(node->id, node->classDecl->id);
        break;
    default:
        break;
    }
}

void ToDot(TSElementListNode *node, std::ostream &out)
{
    out << MakeNode(node->id, "TSElementListNode");

    if (node == NULL)
        return;

    for (const auto &child : node->GetSeq())
    {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
    }
}

void ToDot(TSScriptNode *node, std::ostream &out)
{
    out << "digraph TSScript {\n";
    out << MakeNode(node->id, "Script");

    if (node->elemList != NULL)
    {
        ToDot(node->elemList, out);
        out << MakeConnection(node->id, node->elemList->id);
    }
    out << "}" << std::endl;
}