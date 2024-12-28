#pragma once
#include "expr.h"
#include "node.h"
#include "type.h"
#include <string>

enum class VarModifierType
{
    _LET,
    _VAR,
    _CONST,
};

inline std::string toString(VarModifierType type)
{
    switch (type)
    {
    case VarModifierType::_LET:
        return "let";
    case VarModifierType::_VAR:
        return "var";
    case VarModifierType::_CONST:
        return "const";
    default:
        return "";
    }
}

struct VarDeclarationNode final : Node
{
    std::string identifierStr;
    TypeNode *varType;
    ExpressionNode *initExpression;

    VarDeclarationNode(const std::string varName, TypeNode *varType, ExpressionNode *initExpr)
        : identifierStr{varName}, varType{varType}, initExpression{initExpr}
    {
    }

    std::string toString() const noexcept override { return "VarDeclarationNode"; }
};

struct VarDeclarationListNode final : NodeList<VarDeclarationListNode, VarDeclarationNode>
{
    using NodeList<VarDeclarationListNode, VarDeclarationNode>::NodeList;

    std::string toString() const noexcept override { return "VarDeclarationListNode"; }
};