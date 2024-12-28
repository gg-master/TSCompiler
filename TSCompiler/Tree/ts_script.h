#pragma once
#include "class.h"
#include "func.h"
#include "node.h"
#include "stmt.h"

struct TSScriptNode final : Node
{
    std::vector<StatementNode *> statements{};
    std::vector<FunctionDeclarationNode *> functions{};
    std::vector<ClassDeclarationNode *> classes{};

    TSScriptNode() {}

    void add(StatementNode *node) { statements.push_back(node); }
    void add(FunctionDeclarationNode *node) { functions.push_back(node); }
    void add(ClassDeclarationNode *node) { classes.push_back(node); }

    std::string toString() const noexcept override { return "Script"; }
};
