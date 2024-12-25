// #pragma once
// #include "nodes.h"

// // ====== Expression ====== //

// ExpressionNode *createIDExpressionNode(char *idStr);
// ExpressionNode *createThisExpressionNode();

// ExpressionNode *createIntLiteralExpressionNode(int value);
// ExpressionNode *createFloatLiteralExpressionNode(double value);
// ExpressionNode *createStringLiteralExpressionNode(char *value);
// ExpressionNode *createTrueLiteralExpressionNode();
// ExpressionNode *createFalseLiteralExpressionNode();
// ExpressionNode *createNullLiteralExpressionNode();
// ExpressionNode *createUndefinedLiteralExpressionNode();

// ExpressionNode *createPrefIncrementExpressionNode(ExpressionNode *firstOperand);
// ExpressionNode *createPrefDecrementExpressionNode(ExpressionNode *firstOperand);
// ExpressionNode *createPostIncrementExpressionNode(ExpressionNode *firstOperand);
// ExpressionNode *createPostDecrementExpressionNode(ExpressionNode *firstOperand);

// ExpressionNode *createPlusExpressionNode(ExpressionNode *firstOperand,
//                                          ExpressionNode *secondOperand);
// ExpressionNode *createMinusExpressionNode(ExpressionNode *firstOperand,
//                                           ExpressionNode *secondOperand);
// ExpressionNode *createMulExpressionNode(ExpressionNode *firstOperand,
//                                         ExpressionNode *secondOperand);
// ExpressionNode *createDivExpressionNode(ExpressionNode *firstOperand,
//                                         ExpressionNode *secondOperand);
// ExpressionNode *createLessExpressionNode(ExpressionNode *firstOperand,
//                                          ExpressionNode *secondOperand);
// ExpressionNode *createGreatExpressionNode(ExpressionNode *firstOperand,
//                                           ExpressionNode *secondOperand);

// ExpressionNode *createUPlusExpressionNode(ExpressionNode *firstOperand);
// ExpressionNode *createUMinusExpressionNode(ExpressionNode *firstOperand);

// ExpressionNode *createLogNotExpressionNode(ExpressionNode *firstOperand);
// ExpressionNode *createLogOrExpressionNode(ExpressionNode *firstOperand,
//                                           ExpressionNode *secondOperand);
// ExpressionNode *createLogAndExpressionNode(ExpressionNode *firstOperand,
//                                            ExpressionNode *secondOperand);

// ExpressionNode *createAssignExpressionNode(ExpressionNode *firstOperand,
//                                            ExpressionNode *secondOperand);
// ExpressionNode *createAssignMulExpressionNode(ExpressionNode *firstOperand,
//                                               ExpressionNode *secondOperand);
// ExpressionNode *createAssignDivExpressionNode(ExpressionNode *firstOperand,
//                                               ExpressionNode *secondOperand);
// ExpressionNode *createAssignPlusExpressionNode(ExpressionNode *firstOperand,
//                                                ExpressionNode *secondOperand);
// ExpressionNode *createAssignMinusExpressionNode(ExpressionNode *firstOperand,
//                                                 ExpressionNode *secondOperand);
// ExpressionNode *createAssignLogAndExpressionNode(ExpressionNode *firstOperand,
//                                                  ExpressionNode *secondOperand);
// ExpressionNode *createAssignLogOrExpressionNode(ExpressionNode *firstOperand,
//                                                 ExpressionNode *secondOperand);

// ExpressionNode *createEqualExpressionNode(ExpressionNode *firstOperand,
//                                           ExpressionNode *secondOperand);
// ExpressionNode *createNotEqualExpressionNode(ExpressionNode *firstOperand,
//                                              ExpressionNode *secondOperand);
// ExpressionNode *createStrictEqualExpressionNode(ExpressionNode *firstOperand,
//                                                 ExpressionNode *secondOperand);
// ExpressionNode *createStrictNotEqualExpressionNode(ExpressionNode *firstOperand,
//                                                    ExpressionNode *secondOperand);
// ExpressionNode *createLessEqualExpressionNode(ExpressionNode *firstOperand,
//                                               ExpressionNode *secondOperand);
// ExpressionNode *createGreaterEqualExpressionNode(ExpressionNode *firstOperand,
//                                                  ExpressionNode *secondOperand);

// ExpressionNode *createCommaExpressionNode(ExpressionNode *firstOperand,
//                                           ExpressionNode *secondOperand);
// ExpressionNode *createInstanceOfExpressionNode(ExpressionNode *firstOperand,
//                                                ExpressionNode *secondOperand);
// ExpressionNode *createInExpressionNode(ExpressionNode *firstOperand, ExpressionNode *secondOperand);
// ExpressionNode *createTernaryExpressionNode(ExpressionNode *firstOperand,
//                                             ExpressionNode *secondOperand,
//                                             ExpressionNode *thirdOperand);

// ExpressionNode *createArrayAccessExpressionNode(ExpressionNode *firstOperand,
//                                                 ExpressionNode *secondOperand);
// ExpressionNode *createEmptyArrayElementExpressionNode();
// ExpressionNode *createArrayLiteralFromExpressionList(ExpressionListNode *params);

// ExpressionNode *createFuncCallExpressionNode(char *funcName, ExpressionListNode *params);

// ExpressionNode *createSuperCallExpressionNode(ExpressionListNode *params);

// ExpressionNode *createFieldAccessExpressionNode(ExpressionNode *firstOperand, char *fieldName);
// ExpressionNode *createMethodAccessExpressionNode(ExpressionNode *firstOperand, char *methodName,
//                                                  ExpressionListNode *params);

// ExpressionNode *createNewExpressionNode(ExpressionNode *constructor, ExpressionListNode *params);

// // ====== ExpressionList ====== //

// ExpressionListNode *createExpressionListFromExpression(ExpressionNode *expr);
// ExpressionListNode *createExpressionListNode(ExpressionNode *firstChild);
// ExpressionListNode *addExpressionToExpressionList(ExpressionListNode *list, ExpressionNode *child);
// ExpressionListNode *addExpressionListToExpressionList(ExpressionListNode *fisrtList,
//                                                       ExpressionListNode *secondList);

// // ====== Types ====== //

// TypeNode *createNumberTypeNode();
// TypeNode *createStringTypeNode();
// TypeNode *createBooleanTypeNode();
// TypeNode *createUndefinedTypeNode();
// TypeNode *createVoidTypeNode();
// TypeNode *createNullTypeNode();
// TypeNode *createUserTypeNode(char *typeName);

// TypeNode *createArrayTypeNode(TypeNode *arrayType);

// // ====== VarDeclaration ====== //

// VarDeclarationNode *createVarDeclarationNode(char *idStr, TypeNode *varType,
//                                              ExpressionNode *initExpr);
// VarDeclarationListNode *createVarDeclarationListNode(VarDeclarationNode *firstChild);
// VarDeclarationListNode *addVarDeclarationToVarDeclarationList(VarDeclarationListNode *list,
//                                                               VarDeclarationNode *child);

// // ====== Statement ====== //

// StatementNode *createEmptyStatementNode();
// StatementNode *createExpressionStatementNode(ExpressionNode *expr);
// StatementNode *createVarStatementNode(VarModifierType modifierType,
//                                       VarDeclarationListNode *declList);
// StatementNode *createReturnStatementNode(ExpressionNode *expr);
// StatementNode *createBlockStatementNode(StatementListNode *stmtList);
// StatementNode *createIfElseStatementNode(ExpressionNode *condition, StatementNode *ifBody,
//                                          StatementNode *elseBody);

// StatementNode *createDoWhileStatementNode(StatementNode *body, ExpressionNode *condition);
// StatementNode *createWhileStatementNode(ExpressionNode *condition, StatementNode *body);
// StatementNode *createClassicForStatementNode(ExpressionNode *expr1, ExpressionNode *expr2,
//                                              ExpressionNode *expr3, StatementNode *body);
// StatementNode *createClassicForWithVarDeclStatementNode(VarModifierType modifierType,
//                                                         VarDeclarationListNode *declList,
//                                                         ExpressionNode *expr2,
//                                                         ExpressionNode *expr3, StatementNode *body);
// StatementNode *createForExprInExprStatementNode(ExpressionNode *expr1, ExpressionNode *expr2,
//                                                 StatementNode *body);
// StatementNode *createForVarDeclInExprStatementNode(VarModifierType modifierType,
//                                                    VarDeclarationNode *decl, ExpressionNode *expr,
//                                                    StatementNode *body);

// // ====== StatementList ====== //

// StatementListNode *createStatementListNode(StatementNode *firstChild);
// StatementListNode *addStatementToStatementList(StatementListNode *list, StatementNode *statement);

// // ====== Function declaration ====== //

// FunctionDeclarationNode *createFunctionDeclarationNode(char *funcName,
//                                                        RequiredParameterListNode *params,
//                                                        TypeNode *returnType,
//                                                        StatementListNode *body);

// RequiredParameterListNode *createRequiredParameterListNode(RequiredParameterNode *firstChild);
// RequiredParameterListNode *
// addRequiredParameterToRequiredParameterList(RequiredParameterListNode *list,
//                                             RequiredParameterNode *child);

// RequiredParameterNode *createRequiredParameterNode(char *paramName, TypeNode *paramType);

// // ====== Class declaration ====== //

// ClassDeclarationNode *createClassDeclarationNode(char *className, char *heritageName,
//                                                  ClassElementListNode *body);

// ClassElementListNode *createClassElementListNode(ClassElementNode *firstChild);
// ClassElementListNode *addClassElementToClassElementList(ClassElementListNode *list,
//                                                         ClassElementNode *child);

// ClassElementNode *createClassConstructor(RequiredParameterListNode *params,
//                                          StatementListNode *body);
// ClassElementNode *createClassProperty(char *name, TypeNode *propertyType,
//                                       ExpressionNode *expression);
// ClassElementNode *createClassMethod(char *name, RequiredParameterListNode *params,
//                                     TypeNode *returnType, StatementListNode *body);

// // ====== TSElementNode ====== //

// TSElementNode *createElementFromStatement(StatementNode *stmt);
// TSElementNode *createElementFromFuncDeclaration(FunctionDeclarationNode *funcDecl);
// TSElementNode *createElementFromClassDeclaration(ClassDeclarationNode *classDecl);

// // ====== TSElementListNode ====== //

// TSElementListNode *createTSElementListNode(TSElementNode *elem);

// TSElementListNode *addTSElementNodeToList(TSElementListNode *elemList, TSElementNode *elem);

// // ====== TSScript ====== //

// TSScriptNode *createTSScriptNode(TSElementListNode *elemList);
