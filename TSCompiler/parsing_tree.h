#pragma once
#include "nodes.h"

	// ====== Expression ====== //

struct ExpressionNode* createIDExpression(char* idStr);


	// ====== Statement ====== //

struct StatementNode* createStatementFromExpression(struct ExpressionNode* expr);


	// ====== StatementList ====== //

struct StatementListNode* createStatementListNode(struct StatementNode* firstChild);

struct StatementListNode* addStatementToStatementList(struct StatementListNode* list, struct StatementNode* statement);


	// ====== TSElementNode ====== //

struct TSElementNode* createElementFromStatement(struct StatementNode* stmt);


	// ====== TSElementListNode ====== //

struct TSElementListNode* createTSElementListNode(struct TSElementNode* elem);

struct TSElementListNode* addTSElementNodeToList(struct TSElementListNode* elemList, struct TSElementNode* elem);


	// ====== TSScript ====== //

struct TSScriptNode* createTSScriptNode(struct TSElementListNode* elemList);
