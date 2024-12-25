#pragma once
#include "node.h"
#include "stmt.h"
#include "type.h"

struct RequiredParameterNode final : Node
{
    std::string_view paramName{};
    TypeNode *paramType{};

    std::string_view Name() const noexcept override { return "RequiredParameterNode"; }

    RequiredParameterNode(const std::string_view paramName, TypeNode *paramType)
        : paramName{paramName}, paramType{paramType}
    {
    }
};

struct RequiredParameterListNode final : NodeList<RequiredParameterListNode, RequiredParameterNode>
{
    using NodeList<RequiredParameterListNode, RequiredParameterNode>::NodeList;

    std::string_view Name() const noexcept override { return "RequiredParameterListNode"; }
};

struct FunctionDeclarationNode final : Node
{
    std::string_view funcName{};

    RequiredParameterListNode* params{};
    TypeNode* returnType{};

    StatementListNode* body{};

    FunctionDeclarationNode(const std::string_view funcName, RequiredParameterListNode* params,
        TypeNode* returnType, StatementListNode* body)
        : funcName{ funcName }, params{ params }, returnType{ returnType }, body{ body }
    {
    }
    std::string_view Name() const noexcept override { return "FunctionDeclarationNode"; }
};