#pragma once
#include <string>

#include "expr.h"
#include "node.h"
#include "type.h"

enum class VarModifierType
{
    _LET,
    _VAR,
    _CONST,
};

inline bool isFunctionScopeVar(VarModifierType type)
{
    return type == VarModifierType::_VAR;
}

inline bool isBlockScopeVar(VarModifierType type)
{
    return type == VarModifierType::_CONST || type == VarModifierType::_LET;
}

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
    VarModifierType modifierType{};

    std::string identifierStr{};
    TypeNode *varType{};
    ExpressionNode *initExpression{};

    int scopingLevel = -1;
    VarDeclarationNode *baseNode{};

    int positionInMethod{};

    bool isAssigned = false;

    VarDeclarationNode(const std::string varName, TypeNode *varType,
                       ExpressionNode *initExpr)
        : identifierStr{varName}, varType{varType}, initExpression{initExpr}
    {
    }

    bool operator==(const VarDeclarationNode &other) const
    {
        return identifierStr == other.identifierStr && varType == other.varType;
    }

    bool operator!=(const VarDeclarationNode &other) const
    {
        return !(*this == other);
    }

    std::string toString() const noexcept override
    {
        return "VarDeclarationNode";
    }
};

struct VarDeclarationListNode final
    : NodeList<VarDeclarationListNode, VarDeclarationNode>
{
    using NodeList<VarDeclarationListNode, VarDeclarationNode>::NodeList;

    std::string toString() const noexcept override
    {
        return "VarDeclarationListNode";
    }

    void setModifierType(VarModifierType type)
    {
        for (auto *node : GetSeq())
        {
            node->modifierType = type;
        }
    }
};