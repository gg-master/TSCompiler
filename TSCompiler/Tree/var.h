#pragma once
#include "expr.h"
#include "node.h"
#include "type.h"
#include <string_view>

enum class VarModifierType
{
    _LET,
    _VAR,
    _CONST,
};

inline std::string_view ToString(VarModifierType type)
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
    std::string_view identifierStr;
    TypeNode *varType;
    ExpressionNode *initExpression;

    VarDeclarationNode(const std::string_view varName, TypeNode *varType, ExpressionNode *initExpr)
        : identifierStr{varName}, varType{varType}, initExpression{initExpr}
    {
    }
};

struct VarDeclarationListNode final : NodeList<VarDeclarationListNode, VarDeclarationNode>
{
    using NodeList<VarDeclarationListNode, VarDeclarationNode>::NodeList;
};