#pragma once
#include "node.h"

struct TSElementNode final : Node
{

    enum class TSElementType
    {
        _CLASS,
        _FUNCTION,
        _STATEMENT,
    } type{};

    StatementNode *stmt;
    FunctionDeclarationNode *funcDecl;
    ClassDeclarationNode *classDecl;
};

struct TSElementListNode final : NodeList<TSElementListNode, TSElementNode>
{
    using NodeList<TSElementListNode, TSElementNode>::NodeList;

    std::string_view name() const noexcept override { return "TSElementListNode"; }
};

struct TSScriptNode final : Node
{
    TSElementListNode *elemList;

    TSScriptNode(TSElementListNode *const elemList) : elemList{elemList} {}

    std::string_view name() const noexcept override { return "Program"; }
};