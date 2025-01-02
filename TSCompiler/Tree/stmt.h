#pragma once
#include "node.h"
#include "stmt.h"
#include "var.h"

struct StatementNode final : Node
{
    enum class Type
    {
        _EMPTY,
        _EXPRESSION,
        _VAR,
        _IFELSE,
        _WHILE,
        _DOWHILE,
        _FOR,
        _RETURN,
        _BLOCK,
    } type{};

    // exprStmt, returnStmt, conditшon-head
    struct ExpressionNode *expression{};

    // varStmt, iterations
    enum class VarModifierType modifierType
    {
    };
    struct VarDeclarationListNode *declList{};

    // blockStmt
    struct StatementListNode *stmtList{};

    // condition
    struct StatementNode *ifBody{};
    struct StatementNode *elseBody{};

    // iterations
    struct StatementNode *iterationBody{};
    struct ExpressionNode *iterationExprAdd1{};
    struct ExpressionNode *iterationExprAdd2{};

    std::string toString() const noexcept override { return "StatementNode"; }

    static StatementNode *fromEmptyStmt();
    static StatementNode *fromExprStmt(ExpressionNode *node);
    static StatementNode *fromVarStmt(VarModifierType modifierType,
                                      VarDeclarationListNode *declList);
    static StatementNode *fromReturnStmt(ExpressionNode *node);
    static StatementNode *fromBlockStmt(StatementListNode *stmtList);
    static StatementNode *fromIfElseStmt(ExpressionNode *condition,
                                         StatementNode *ifBody,
                                         StatementNode *elseBody);

    static StatementNode *fromDoWhileStmt(StatementNode *body,
                                          ExpressionNode *condition);
    static StatementNode *fromWhileStmt(ExpressionNode *condition,
                                        StatementNode *body);
    static StatementNode *fromClassicForStmt(ExpressionNode *expr1,
                                             ExpressionNode *expr2,
                                             ExpressionNode *expr3,
                                             StatementNode *body);
    static StatementNode *fromClassicForWithVarDeclStmt(
        VarModifierType modifierType, VarDeclarationListNode *declList,
        ExpressionNode *expr2, ExpressionNode *expr3, StatementNode *body);
    static StatementNode *fromForExprInExprStmt(ExpressionNode *expr1,
                                                ExpressionNode *expr2,
                                                StatementNode *body);
    static StatementNode *fromForVarDeclInExprStmt(VarModifierType modifierType,
                                                   VarDeclarationNode *decl,
                                                   ExpressionNode *expr,
                                                   StatementNode *body);

    std::vector<VarDeclarationNode *> getAllFunctionScopedVars();
};

struct StatementListNode final : NodeList<StatementListNode, StatementNode>
{
    using NodeList<StatementListNode, StatementNode>::NodeList;

    std::string toString() const noexcept override
    {
        return "StatementListNode";
    }
};
