#include "stmt.h"

StatementNode *StatementNode::fromEmptyStmt()
{
    auto *stmt = new StatementNode{};
    stmt->type = StatementNode::Type::_EMPTY;
    return stmt;
}
StatementNode *StatementNode::fromExprStmt(ExpressionNode *node)
{
    auto *stmt = new StatementNode{};
    stmt->type = StatementNode::Type::_EXPRESSION;
    stmt->expression = node;
    return stmt;
}
StatementNode *StatementNode::fromVarStmt(VarModifierType modifierType,
                                          VarDeclarationListNode *declList)
{
    auto *node = new StatementNode{};
    node->type = StatementNode::Type::_VAR;
    node->modifierType = modifierType;
    node->declList = declList;
    node->declList->setModifierType(modifierType);
    return node;
}

StatementNode *StatementNode::fromVarDecl(VarDeclarationNode *varDecl)
{
    auto *node = new StatementNode{};
    node->type = StatementNode::Type::_VAR;
    node->modifierType = varDecl->modifierType;
    node->declList = new VarDeclarationListNode(varDecl);
    return node;
}

StatementNode *StatementNode::fromReturnStmt(ExpressionNode *node)
{
    auto *stmt = new StatementNode{};
    stmt->type = StatementNode::Type::_RETURN;
    stmt->expression = node;
    return stmt;
}
StatementNode *StatementNode::fromBlockStmt(StatementListNode *stmtList)
{
    auto *stmt = new StatementNode{};
    stmt->type = StatementNode::Type::_BLOCK;
    stmt->stmtList = stmtList;
    return stmt;
}
StatementNode *StatementNode::fromIfElseStmt(ExpressionNode *condition,
                                             StatementNode *ifBody,
                                             StatementNode *elseBody)
{
    auto *stmt = new StatementNode{};
    stmt->type = StatementNode::Type::_IFELSE;
    stmt->expression = condition;
    stmt->ifBody = ifBody;
    stmt->elseBody = elseBody;
    return stmt;
}

StatementNode *StatementNode::fromDoWhileStmt(StatementNode *body,
                                              ExpressionNode *condition)
{
    auto *stmt = new StatementNode{};
    stmt->type = StatementNode::Type::_DOWHILE;
    stmt->iterationBody = body;
    stmt->expression = condition;
    return stmt;
}
StatementNode *StatementNode::fromWhileStmt(ExpressionNode *condition,
                                            StatementNode *body)
{
    auto *stmt = new StatementNode{};
    stmt->type = StatementNode::Type::_WHILE;
    stmt->iterationBody = body;
    stmt->expression = condition;
    return stmt;
}
StatementNode *StatementNode::fromClassicForStmt(ExpressionNode *expr1,
                                                 ExpressionNode *expr2,
                                                 ExpressionNode *expr3,
                                                 StatementNode *body)
{
    auto *stmt = new StatementNode{};
    stmt->type = StatementNode::Type::_FOR;
    stmt->iterationBody = body;
    stmt->expression = expr1;
    stmt->iterationExprAdd1 = expr2;
    stmt->iterationExprAdd2 = expr3;
    return stmt;
}
StatementNode *StatementNode::fromClassicForWithVarDeclStmt(
    VarModifierType modifierType, VarDeclarationListNode *declList,
    ExpressionNode *expr2, ExpressionNode *expr3, StatementNode *body)
{
    auto *stmt = new StatementNode{};
    stmt->type = StatementNode::Type::_FOR;
    stmt->iterationBody = body;
    stmt->modifierType = modifierType;
    stmt->declList = declList;
    stmt->iterationExprAdd1 = expr2;
    stmt->iterationExprAdd2 = expr3;
    return stmt;
}
StatementNode *StatementNode::fromForExprInExprStmt(ExpressionNode *expr1,
                                                    ExpressionNode *expr2,
                                                    StatementNode *body)
{
    auto *stmt = new StatementNode{};
    stmt->type = StatementNode::Type::_FOR;
    stmt->iterationBody = body;
    stmt->expression = expr1;
    stmt->iterationExprAdd1 = expr2;
    return stmt;
}
StatementNode *StatementNode::fromForVarDeclInExprStmt(
    VarModifierType modifierType, VarDeclarationNode *decl,
    ExpressionNode *expr, StatementNode *body)
{
    auto *stmt = new StatementNode{};
    stmt->type = StatementNode::Type::_FOR;
    stmt->iterationBody = body;
    stmt->modifierType = modifierType;
    stmt->declList->add(decl);
    stmt->expression = expr;

    stmt->declList->setModifierType(modifierType);
    return stmt;
}

std::vector<VarDeclarationNode *> StatementNode::getAllFunctionScopedVars()
{
    std::vector<VarDeclarationNode *> variables;

    if (type == StatementNode::Type::_VAR && isFunctionScopeVar(modifierType))
    {
        variables.insert(variables.end(), declList->GetSeq().begin(),
                         declList->GetSeq().end());
    }
    if (stmtList)
    {
        for (auto *stmt : stmtList->GetSeq())
        {
            auto vars = stmt->getAllFunctionScopedVars();
            variables.insert(variables.end(), vars.begin(), vars.end());
        }
    }
    if (ifBody)
    {
        auto vars = ifBody->getAllFunctionScopedVars();
        variables.insert(variables.end(), vars.begin(), vars.end());
    }
    if (elseBody)
    {
        auto vars = elseBody->getAllFunctionScopedVars();
        variables.insert(variables.end(), vars.begin(), vars.end());
    }
    if (iterationBody)
    {
        auto vars = iterationBody->getAllFunctionScopedVars();
        variables.insert(variables.end(), vars.begin(), vars.end());
    }
    return variables;
}
