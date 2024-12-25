#pragma once
#include "class.h"
#include "func.h"
#include "node.h"
#include "stmt.h"

struct TSElementNode final : Node
{
    enum class Type
    {
        _CLASS,
        _FUNCTION,
        _STATEMENT,
    } type{};

    StatementNode *stmt;
    FunctionDeclarationNode *funcDecl;
    ClassDeclarationNode *classDecl;

    TSElementNode(StatementNode *stmt) : type{Type::_STATEMENT}, stmt{stmt} {}
    TSElementNode(FunctionDeclarationNode *funcDecl) : type{Type::_FUNCTION}, funcDecl{funcDecl} {}
    TSElementNode(ClassDeclarationNode *classDecl) : type{Type::_CLASS}, classDecl{classDecl} {}

    std::string_view Name() const noexcept override { return "TSElementNode"; }
};

struct TSElementListNode final : NodeList<TSElementListNode, TSElementNode>
{
    using NodeList<TSElementListNode, TSElementNode>::NodeList;

    std::string_view Name() const noexcept override { return "TSElementListNode"; }
};

struct TSScriptNode final : Node
{
    TSElementListNode *elemList;

    TSScriptNode(TSElementListNode *const elemList) : elemList{elemList} {}

    std::string_view Name() const noexcept override { return "Script"; }
};
