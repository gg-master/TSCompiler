#include "dot.h"

#include <process.h>

#include <iostream>
#include <string>

void RunDot(const std::string dotPath, const std::string dotFilePath)
{
    _spawnl(_P_NOWAIT, dotPath.data(), "dot", "-O", "-Tpng", "-Gcharset=l1", dotFilePath.data(),
            NULL);
}

std::string MakeNode(const std::size_t id, const std::string name,
                     const std::string style = "")
{
    auto res = std::to_string(id) + " [label=\"" + name + "\"]";
    if (!style.empty())
    {
        res += "[style = \"" + style + "\"]";
    }
    res += "\n";
    return res;
}

std::string MakeConnection(const size_t id1, const size_t id2,
                           std::string note = "")
{
    auto res = std::to_string(id1) + " -> " + std::to_string(id2);

    if (!note.empty())
        res += " [label=\"" + note + "\"]";

    res += "\n";
    return res;
}

void ToDot(TypeNode *node, std::ostream &out)
{
    if (!node)
        return;

    std::string name = "TypeNode:\n" + node->toString();
    out << MakeNode(node->id, name);
}

void ToDot(VarDeclarationNode *node, std::ostream &out)
{
    std::string name =
        "VarDeclarationNode\nModifier: " + toString(node->modifierType) +
        "\nName: " + node->identifierStr;
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
        name = "IdentName:\n" + node->identifierString;
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }
        out << MakeNode(node->id, name);
        break;
    case ExpressionNode::Type::_INT_LIT:
        name = "IntLiteral:\n" + std::to_string(node->intValue);
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }
        out << MakeNode(node->id, name);
        break;
    case ExpressionNode::Type::_FLOAT_LIT:
        name = "FloatLiteral:\n" + std::to_string(node->floatValue);
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }
        out << MakeNode(node->id, name);
        break;
    case ExpressionNode::Type::_STRING_LIT:
        name = "StringLiteral:\n\\\"" + node->stringValue + "\\\"";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }
        out << MakeNode(node->id, name);
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
        name = "BooleanLiteral:\n" + name;
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }
        out << MakeNode(node->id, name);
        break;
    case ExpressionNode::Type::_NULL_LIT:
        name = "NullLiteral";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }
        out << MakeNode(node->id, name);
        break;
    case ExpressionNode::Type::_UNDEFINED_LIT:
        name = "UndefinedLiteral";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }
        out << MakeNode(node->id, name);
        break;

    case ExpressionNode::Type::_PREF_INCREMENT:
        name = "PrefIncrement";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionNode::Type::_PREF_DECREMENT:
        name = "PrefDecrement";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionNode::Type::_POST_INCREMENT:
        name = "PostIncrement";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionNode::Type::_POST_DECREMENT:
        name = "PostDecrement";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;

    case ExpressionNode::Type::_PLUS:
        name = "PlusOperator";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_MINUS:
        name = "MinusOperator";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_MUL:
        name = "MulOperator";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_DIV:
        name = "DivOperator";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_LESS:
        name = "LessOperator";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_GREAT:
        name = "GreatOperator";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;

    case ExpressionNode::Type::_UPLUS:
        name = "UnaryPlusOperator";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionNode::Type::_UMINUS:
        name = "UnaryMinusOperator";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;

    case ExpressionNode::Type::_NOT:
        name = "LogicalNot";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionNode::Type::_LOGICAL_OR:
        name = "LogicalOr";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_LOGICAL_AND:
        name = "LogicalAnd";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_ASSIGN_TO_ARRAY_ELEMENT:
        name = "AssignToArrayElement";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id), "arr";
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id, "index");
        ToDot(node->thirdOperand, out);
        out << MakeConnection(node->id, node->thirdOperand->id, "value");
        break;
    case ExpressionNode::Type::_ASSIGN_TO_FIELD:
        name = "AssignToField";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id, "obj");
        ToDot(node->actualField, out);
        out << MakeConnection(node->id, node->actualField->id, "prop");
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id, "value");
        break;
    case ExpressionNode::Type::_ASSIGN:
        name = "Assign";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_ASSIGN_MUL:
        name = "AssignMul";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_ASSIGN_DIV:
        name = "AssignDiv";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_ASSIGN_PLUS:
        name = "AssignPlus";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_ASSIGN_MINUS:
        name = "AssignMinus";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_ASSIGN_LOGICAL_AND:
        name = "AssignAnd";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_ASSIGN_LOGICAL_OR:
        name = "AssignOr";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;

    case ExpressionNode::Type::_EQUAL:
        name = "Equal";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_NOT_EQUAL:
        name = "NotEqual";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }
        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_LESS_EQUAL:
        name = "LessEqual";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_GREAT_EQUAL:
        name = "GreaterEqual";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;

    case ExpressionNode::Type::_COMMA:
        name = "CommaOperator";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_INSTANCEOF:
        name = "InstanceofOperator";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_IN:
        name = "InOperator";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionNode::Type::_TERNARY:
        name = "Ternary";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id, "condition");
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id, "ifTrue");
        ToDot(node->thirdOperand, out);
        out << MakeConnection(node->id, node->thirdOperand->id, "ifFalse");
        break;

    case ExpressionNode::Type::_ARRAY_CREATION:
        name = "ArrayCreation";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        if (node->params != NULL)
        {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        break;
    case ExpressionNode::Type::_ARRAY_EMPTY_ELEMENT:
        name = "ArrayEmptyElement";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        break;
    case ExpressionNode::Type::_ARRAY_ACCESS:
        name = "ArrayAccess";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id, "array");
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id, "index");
        break;

    case ExpressionNode::Type::_FUNC_CALL:
        name = "FuncCall:\nFuncName: " + node->identifierString;
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id, "returnType");
        }

        out << MakeNode(node->id, name);
        if (node->params != NULL)
        {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        break;
    case ExpressionNode::Type::_SUPER_CALL:
        name = "SuperCall";
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id);
        }

        out << MakeNode(node->id, name);
        if (node->params != NULL)
        {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        break;
    case ExpressionNode::Type::_FIELD_ACCESS:
        name = "FieldAccess:\nFieldName: " + node->identifierString;
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id, "fieldType");
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id, "object");
        break;
    case ExpressionNode::Type::_METHOD_CALL:
        name = "MethodAccess\nMethodName: " + node->identifierString;
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id, "returnType");
        }

        out << MakeNode(node->id, name);
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id, "object");
        if (node->params != NULL)
        {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        break;
    case ExpressionNode::Type::_NEW:
        name = "NewOperator:\nConstructor: " + node->identifierString;
        if (node->exprType)
        {
            name += "\nJvmType: " + node->exprType->toString();
            ToDot(node->exprType, out);
            out << MakeConnection(node->id, node->exprType->id, "objType");
        }

        out << MakeNode(node->id, name);
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
        name = "VarStmtNode\nModifierType: " + toString(node->modifierType);
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
    case StatementNode::Type::_FOR_EACH:
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
            out << MakeConnection(node->id, node->iterationExprAdd1->id,
                                  "exprAdd1");
        }

        if (node->iterationExprAdd2 != NULL)
        {
            ToDot(node->iterationExprAdd2, out);
            out << MakeConnection(node->id, node->iterationExprAdd2->id,
                                  "exprAdd2");
        }

        if (node->declList != NULL)
        {
            ToDot(node->declList, out);
            out << MakeConnection(node->id, node->declList->id,
                                  toString(node->modifierType));
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
    out << MakeNode(node->id, "RequiredParameterNode\nName: " +
                                  std::string{node->paramName});

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
    out << MakeNode(node->id, "FunctionDeclarationNode\nName: " +
                                  std::string{node->funcName});

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
    std::string name;
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
        name = "ClassPropertyNode\nName: " + node->name;

        out << MakeNode(node->id, name);

        if (node->propertyAndReturnType != NULL)
        {
            ToDot(node->propertyAndReturnType, out);
            out << MakeConnection(node->id, node->propertyAndReturnType->id,
                                  "type");
        }
        if (node->expression != NULL)
        {
            ToDot(node->expression, out);
            out << MakeConnection(node->id, node->expression->id, "init");
        }
        if (node->baseNode)
        {
            ToDot(node->baseNode, out);
            out << MakeConnection(node->id, node->baseNode->id, "baseNode");
        }
        break;
    case ClassElementNode::Type::_METHOD:
        out << MakeNode(node->id,
                        "ClassMethodNode\nName: " + std::string{node->name});
        if (node->params != NULL)
        {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }

        if (node->propertyAndReturnType != NULL)
        {
            ToDot(node->propertyAndReturnType, out);
            out << MakeConnection(node->id, node->propertyAndReturnType->id,
                                  "type");
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
    std::string name =
        "ClassDeclarationNode\nName: " + std::string{node->className};
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

void ToDot(TSScriptNode *node, std::ostream &out)
{
    out << "digraph TSScript {\n";
    out << MakeNode(node->id, "Script");

    for (StatementNode *child : node->statements)
    {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
    }

    for (FunctionDeclarationNode *child : node->functions)
    {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
    }

    for (ClassDeclarationNode *child : node->classes)
    {
        if (child->className.starts_with("JavaRTL"))
            continue;

        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
    }
    out << "}" << std::endl;
}