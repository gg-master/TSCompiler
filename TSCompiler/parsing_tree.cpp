#include <stdlib.h>
#include "parsing_tree.h"


int ID = 0;

	// ====== Expression ====== //

struct ExpressionNode* createIDExpression(char* idStr) {
    struct ExpressionNode* node = (struct ExpressionNode*)malloc(sizeof(struct ExpressionNode));
    node->type = ExpressionType::_IDENTIFIER;
    node->identifierString = idStr;
    node->leftOperand = NULL;
    node->rightOperand = NULL;
    node->nextExpression = NULL;
    node->id = ID++;
    return node;
}

    // ====== Statement ====== //

struct StatementNode* createStatementFromExpression(struct ExpressionNode* expr) {
    struct StatementNode* stmt = (struct StatementNode*)malloc(sizeof(struct StatementNode));
    stmt->type = StatementType::_EXPRESSION;
    stmt->expression = expr;
    stmt->id = ID++;
    return stmt;
}

    // ====== StatementList ====== //

struct StatementListNode* createStatementListNode(struct StatementNode* firstChild) {
    struct StatementListNode* node = (struct StatementListNode*)malloc(sizeof(struct StatementListNode));
    node->first = firstChild;
    node->last = firstChild;
    node->id = ID++;
    return node;
}

struct StatementListNode* addStatementToStatementList(struct StatementListNode* list, struct StatementNode* statement) {
    list->last->next = statement;
    list->last = statement;
    return list;
}

    // ====== TSElementNode ====== //

struct TSElementNode* createElementFromStatement(struct StatementNode* stmt) {
    struct TSElementNode* node = (struct TSElementNode*)malloc(sizeof(struct TSElementNode));
    node->stmt = stmt;
    node->type = TSElementType::_STATEMENT_LIST;
    node->next = NULL;
    node->id = ID++;
    return node;
}

    // ====== TSElementListNode ====== //

struct TSElementListNode* createTSElementListNode(struct TSElementNode* elem) {
    struct TSElementListNode* node = (struct TSElementListNode*)malloc(sizeof(struct TSElementListNode));
    node->id = ID++;
    node->first = elem;
    node->last = elem;
    return node;
}

struct TSElementListNode* addTSElementNodeToList(struct TSElementListNode* elemList, struct TSElementNode* elem) {
    elemList->last->next = elem;
    elemList->last = elem;
    return elemList;
}

struct TSScriptNode* createTSScriptNode(struct TSElementListNode* elemList) {
    struct TSScriptNode* node = (struct TSScriptNode*)malloc(sizeof(struct TSScriptNode));
    node->id = ID++;
    node->elemList = elemList;
    return node;
}
