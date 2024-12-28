#pragma once
#include "node.h"
#include "stmt.h"
#include "type.h"

struct RequiredParameterNode final : Node
{
    std::string paramName{};
    TypeNode *paramType{};

    std::string toString() const noexcept override
    {
        return "RequiredParameterNode";
    }

    RequiredParameterNode(const std::string paramName, TypeNode *paramType)
        : paramName{paramName}, paramType{paramType}
    {
    }
};

struct RequiredParameterListNode final
    : NodeList<RequiredParameterListNode, RequiredParameterNode>
{
    using NodeList<RequiredParameterListNode, RequiredParameterNode>::NodeList;

    std::string toString() const noexcept override
    {
        return "RequiredParameterListNode";
    }
};

struct FunctionDeclarationNode final : Node
{
    std::string funcName{};

    RequiredParameterListNode *params{};
    TypeNode *returnType{};

    StatementListNode *body{};

    FunctionDeclarationNode(const std::string funcName,
                            RequiredParameterListNode *params,
                            TypeNode *returnType, StatementListNode *body)
        : funcName{funcName}, params{params}, returnType{returnType}, body{body}
    {
    }
    std::string toString() const noexcept override
    {
        return "FunctionDeclarationNode";
    }
};
