#pragma once
#include "nodes.h"

	// ====== Expression ====== //

// Сделано
ExpressionNode* createIDExpressionNode(char* idStr);

// Сделано
ExpressionNode* createPlusExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);
ExpressionNode* createMinusExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);
ExpressionNode* createMulExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);
ExpressionNode* createDivExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);
ExpressionNode* createLessExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);
ExpressionNode* createGreatExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);

// Сделано
ExpressionNode* createUPlusExpressionNode(ExpressionNode* firstOperand);
ExpressionNode* createUMinusExpressionNode(ExpressionNode* firstOperand);

// Сделано
ExpressionNode* createLogNotExpressionNode(ExpressionNode* firstOperand);
ExpressionNode* createLogOrExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);
ExpressionNode* createLogAndExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);

// Сделано
ExpressionNode* createCommaExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);
ExpressionNode* createBracketsExpressionNode(ExpressionNode* expr);

// Сделано
ExpressionNode* createThisExpressionNode();
ExpressionNode* createSuperExpressionNode(); 
ExpressionNode* createFuncCallExpressionNode(char* idStr, ExpressionListNode* params);

// Сделано не до конца: требуется ArrayAccess
ExpressionNode* createEmptyArrayElementExpressionNode();
ExpressionNode* createExpressionFromExpressionList(ExpressionListNode* params);
ExpressionNode* createArrayAccessElementExpressionNode();

// Сделано
ExpressionNode* createPrefIncrementExpressionNode(ExpressionNode* firstOperand);
ExpressionNode* createPrefDecrementExpressionNode(ExpressionNode* firstOperand);
ExpressionNode* createPostIncrementExpressionNode(ExpressionNode* firstOperand);
ExpressionNode* createPostDecrementExpressionNode(ExpressionNode* firstOperand);

// ?
ExpressionNode* createTrueLiteralExpressionNode();
ExpressionNode* createFalseLiteralExpressionNode();
ExpressionNode* createIntLiteralExpressionNode(int value);
ExpressionNode* createFloatLiteralExpressionNode(double value);
ExpressionNode* createStringLiteralExpressionNode(char* value);
ExpressionNode* createNullLiteralExpressionNode();


/* add other binary and unary operations */

ExpressionNode* createFieldAccessExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand);
ExpressionNode* createMethodAccessExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand, ExpressionListNode* params);


    // ====== ExpressionList ====== //

ExpressionListNode* createExpressionListFromExpression(ExpressionNode* expr);

ExpressionListNode* createExpressionListNode(ExpressionNode* firstChild);
ExpressionListNode* addExpressionToExpressionList(ExpressionListNode* list, ExpressionNode* child);
ExpressionListNode* addExpressionListToExpressionList(ExpressionListNode* fisrtList, ExpressionListNode* secondList);


	// ====== Statement ====== //

StatementNode* createStatementFromExpression(ExpressionNode* expr);
StatementNode* createStatementFromVarStatement(VarStatementNode* varStmt);


	// ====== StatementList ====== //

StatementListNode* createStatementListNode(StatementNode* firstChild);
StatementListNode* addStatementToStatementList(StatementListNode* list, StatementNode* statement);


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

VarStatementNode* createVarStatementNode(VarModifierType modifierType, VarDeclarationListNode* declList);

VarDeclarationNode* createVarDeclarationNode(char* idStr, TypeNode* varType, ExpressionNode* initExpr);

VarDeclarationListNode* createVarDeclarationListNode(VarDeclarationNode* firstChild);
VarDeclarationListNode* addVarDeclarationToVarDeclarationList(VarDeclarationListNode* list, VarDeclarationNode* child);


	// ====== TSElementNode ====== //

TSElementNode* createElementFromStatement(StatementNode* stmt);


	// ====== TSElementListNode ====== //

TSElementListNode* createTSElementListNode(TSElementNode* elem);

TSElementListNode* addTSElementNodeToList(TSElementListNode* elemList, TSElementNode* elem);


	// ====== TSScript ====== //

TSScriptNode* createTSScriptNode(TSElementListNode* elemList);
