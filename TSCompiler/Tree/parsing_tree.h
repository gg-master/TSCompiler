#pragma once
#include "nodes.h"

	// ====== Expression ====== //

ExpressionNode* createIDExpressionNode(char* idStr);
ExpressionNode* createIntLiteralExpressionNode(int value);
ExpressionNode* createFloatLiteralExpressionNode(double value);
ExpressionNode* createTrueLiteralExpressionNode();
ExpressionNode* createFalseLiteralExpressionNode();
ExpressionNode* createStringLiteralExpressionNode(char* value);
ExpressionNode* createNullLiteralExpressionNode();

ExpressionNode* createThisExpressionNode();
ExpressionNode* createSuperExpressionNode();

ExpressionNode* createPlusExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);
ExpressionNode* createMinusExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);
ExpressionNode* createDivExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);
ExpressionNode* createMulExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);

ExpressionNode* createUPlusExpressionNode(ExpressionNode* firstOperand);
ExpressionNode* createUMinusExpressionNode(ExpressionNode* firstOperand);

ExpressionNode* createPrefIncrementExpressionNode(ExpressionNode* firstOperand);
ExpressionNode* createPrefDecrementExpressionNode(ExpressionNode* firstOperand);
ExpressionNode* createPostIncrementExpressionNode(ExpressionNode* firstOperand);
ExpressionNode* createPostDecrementExpressionNode(ExpressionNode* firstOperand);

/* add other binary and unary operations */

ExpressionNode* createCommaExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);
ExpressionNode* createBracketsExpressionNode(ExpressionNode* expr);

ExpressionNode* createFieldAccessExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);
ExpressionNode* createMethodAccessExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand, ExpressionListNode* params);
ExpressionNode* createFuncCallExpressionNode(char* idStr, ExpressionListNode* params);


ExpressionNode* createEmptyArrayElementExpressionNode();

ExpressionNode* createExpressionFromExpressionList(ExpressionListNode* params);


    // ====== ExpressionList ====== //

ExpressionListNode* createExpressionListFromExpression(ExpressionNode* expr);

ExpressionListNode* createExpressionListNode(ExpressionNode* firstChild);
ExpressionListNode* addExpressionToExpressionList(ExpressionListNode* list, ExpressionNode* child);
ExpressionListNode* addExpressionListToExpressionList(ExpressionListNode* fisrtList, ExpressionListNode* secondList);

	// ====== Types ====== //

TypeNode* createNumberTypeNode();
TypeNode* createStringTypeNode();
TypeNode* createBooleanTypeNode();
TypeNode* createUndefinedTypeNode();
TypeNode* createVoidTypeNode();
TypeNode* createNullTypeNode();

TypeNode* createArrayTypeNode(TypeNode* arrayType);
TypeNode* createTypeFromTupleType(TupleTypeNode* tupleNode);

TupleTypeNode* createTupleTypeNode(TypeNode* firstChild);
TupleTypeNode* addTypeToTupleType(TupleTypeNode* list, TypeNode* typeNode);


	// ====== VarDeclaration ====== //

VarDeclarationNode* createVarDeclarationNode(char* idStr, TypeNode* varType, ExpressionNode* initExpr);

VarDeclarationListNode* createVarDeclarationListNode(VarDeclarationNode* firstChild);
VarDeclarationListNode* addVarDeclarationToVarDeclarationList(VarDeclarationListNode* list, VarDeclarationNode* child);


	// ====== Statement ====== //

StatementNode* createExpressionStatementNode(ExpressionNode* expr);
StatementNode* createVarStatementNode(VarModifierType modifierType, VarDeclarationListNode* declList);


	// ====== StatementList ====== //

StatementListNode* createStatementListNode(StatementNode* firstChild);
StatementListNode* addStatementToStatementList(StatementListNode* list, StatementNode* statement);


	// ====== TSElementNode ====== //

TSElementNode* createElementFromStatement(StatementNode* stmt);


	// ====== TSElementListNode ====== //

TSElementListNode* createTSElementListNode(TSElementNode* elem);

TSElementListNode* addTSElementNodeToList(TSElementListNode* elemList, TSElementNode* elem);


	// ====== TSScript ====== //

TSScriptNode* createTSScriptNode(TSElementListNode* elemList);
