#include <stdlib.h>
#include "parsing_tree.h"


int ID = 0;

	// ====== Expression ====== //

ExpressionNode* createIDExpressionNode(char* idStr) {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_IDENTIFIER;
    node->identifierString = idStr;
    node->id = ID++;
    return node;
}

ExpressionNode* createIntLiteralExpressionNode(int value) {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_INT_LIT;
    node->intValue = value;
    node->id = ID++;
    return node;
}
ExpressionNode* createFloatLiteralExpressionNode(double value) {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_FLOAT_LIT;
    node->floatValue = value;
    node->id = ID++;
    return node;
}
ExpressionNode* createTrueLiteralExpressionNode() {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_BOOLEAN_LIT;
    node->boolValue = 1;
    node->id = ID++;
    return node;
}
ExpressionNode* createFalseLiteralExpressionNode() {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_BOOLEAN_LIT;
    node->boolValue = 0;
    node->id = ID++;
    return node;
}
ExpressionNode* createStringLiteralExpressionNode(char* value) {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_STRING_LIT;
    node->stringValue = value;
    node->id = ID++;
    return node;
}
ExpressionNode* createNullLiteralExpressionNode() {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_NULL_LIT;
    node->id = ID++;
    return node;
}

ExpressionNode* createThisExpressionNode() {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_THIS;
    node->id = ID++;
    return node;
}
ExpressionNode* createSuperExpressionNode() {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_SUPER;
    node->id = ID++;
    return node;
}

ExpressionNode* createPlusExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand) {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_PLUS;
    node->firstOperand = firstOperand;
    node->secondOperand = secondOperand;
    node->id = ID++;
    return node;
}
ExpressionNode* createMinusExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand) {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_MINUS;
    node->firstOperand = firstOperand;
    node->secondOperand = secondOperand;
    node->id = ID++;
    return node;
}
ExpressionNode* createDivExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand) {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_DIV;
    node->firstOperand = firstOperand;
    node->secondOperand = secondOperand;
    node->id = ID++;
    return node;
}
ExpressionNode* createMulExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand) {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_MUL;
    node->firstOperand = firstOperand;
    node->secondOperand = secondOperand;
    node->id = ID++;
    return node;
}


/* add other binary and unary operations */

ExpressionNode* createCommaExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand) {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_COMMA;
    node->firstOperand = firstOperand;
    node->secondOperand = secondOperand;
    node->id = ID++;
    return node;
}
ExpressionNode* createBracketsExpressionNode(ExpressionNode* expr) {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_BRACKETS;
    node->firstOperand = expr;
    node->id = ID++;
    return node;
}

ExpressionNode* createMethodAccessExpressionNode(ExpressionNode* firstOperand, ExpressionNode* secondOperand, ExpressionListNode* params) {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_METHOD_ACCESS;
    node->firstOperand = firstOperand;
    node->secondOperand = secondOperand;
    node->params = params;
    node->id = ID++;
    return node;
}
ExpressionNode* createFuncCallExpressionNode(char* idStr, ExpressionListNode* params) {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_FUNC_CALL;
    node->identifierString = idStr;
    node->params = params;
    node->id = ID++;
    return node;
}

ExpressionNode* createEmptyArrayElementExpressionNode() {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_ARRAY_EMPTY_ELEMENT;
    node->id = ID++;
    return node;
}

ExpressionNode* createExpressionFromExpressionList(ExpressionListNode* params) {
    auto* node = new ExpressionNode{};
    node->type = ExpressionType::_ARRAY_CREATION;

    // removing last empty array element
    if (params->first != nullptr && params->last != nullptr 
        && params->last->type == ExpressionType::_ARRAY_EMPTY_ELEMENT) {
        auto* child = params->first;
        while (child->next != nullptr && child->next != params->last) {
            child = child->next;
        }

        child->next = nullptr;
        
        if (params->first == params->last) {
            params->first = nullptr;
            child = nullptr;
        }
        free(params->last);
        params->last = child;
    }
    node->params = params;
    node->id = ID++;
    return node;
}


    // ====== ExpressionList ====== //

ExpressionListNode* createExpressionListFromExpression(ExpressionNode* expr) {
    ExpressionListNode* leftExprList = nullptr;
    ExpressionListNode* rightExprList = nullptr;

    if (expr == nullptr) {
        return new ExpressionListNode{};
    }
    switch (expr->type)
    {
    case ExpressionType::_COMMA:
        leftExprList = createExpressionListFromExpression(expr->firstOperand);
        rightExprList = createExpressionListFromExpression(expr->secondOperand);

        leftExprList->last->next = rightExprList->first;
        leftExprList->last = rightExprList->last;

        free(rightExprList);
        return leftExprList;
    default:
        auto* node = new ExpressionListNode{};
        node->first = expr;
        node->last = expr;
        node->id = ID++;
        return node;
    }
}

ExpressionListNode* createExpressionListNode(ExpressionNode* firstChild) {
    auto* node = new ExpressionListNode{};
    node->first = firstChild;
    node->last = firstChild;
    node->id = ID++;
    return node;
}
ExpressionListNode* addExpressionToExpressionList(ExpressionListNode* list, ExpressionNode* child) {
    list->last->next = child;
    list->last = child;
    return list;
}
ExpressionListNode* addExpressionListToExpressionList(ExpressionListNode* fisrtList, ExpressionListNode* secondList) {
    fisrtList->last->next = secondList->first;
    fisrtList->last = secondList->last;

    free(secondList);
    return fisrtList;
}


	// ====== Types ====== //

TypeNode* createNumberTypeNode() {
    auto* node = new TypeNode{};
    node->type = TypeType::_NUMBER;
    node->id = ID++;
    return node;
}
TypeNode* createStringTypeNode() {
    auto* node = new TypeNode{};
    node->type = TypeType::_STRING;
    node->id = ID++;
    return node;
}
TypeNode* createBooleanTypeNode() {
    auto* node = new TypeNode{};
    node->type = TypeType::_BOOLEAN;
    node->id = ID++;
    return node;
}
TypeNode* createUndefinedTypeNode() {
    auto* node = new TypeNode{};
    node->type = TypeType::_UNDEFINED;
    node->id = ID++;
    return node;
}
TypeNode* createVoidTypeNode() {
    auto* node = new TypeNode{};
    node->type = TypeType::_VOID;
    node->id = ID++;
    return node;
}
TypeNode* createNullTypeNode() {
    auto* node = new TypeNode{};
    node->type = TypeType::_NULL;
    node->id = ID++;
    return node;
}
TypeNode* createArrayTypeNode(TypeNode* arrayType) {
    auto* node = new TypeNode{};
    node->type = TypeType::_ARRAY;
    node->arrayType = arrayType;
    node->id = ID++;
    return node;
}
TypeNode* createTypeFromTupleType(TupleTypeNode* tupleNode) {
    auto* node = new TypeNode{};
    node->type = TypeType::_TUPLE;
    node->tupleNode = tupleNode;
    node->id = ID++;
    return node;
}

TupleTypeNode* createTupleTypeNode(TypeNode* firstChild) {
    auto* node = new TupleTypeNode{};
    node->first = firstChild;
    node->last = firstChild;
    node->id = ID++;
    return node;
}
TupleTypeNode* addTypeToTupleType(TupleTypeNode* list, TypeNode* typeNode) {
    list->last->next = typeNode;
    list->last = typeNode;
    return list;
}

	// ====== Variables ====== //

VarDeclarationNode* createVarDeclarationNode(char* idStr, TypeNode* varType, ExpressionNode* initExpr) {
    auto* node = new VarDeclarationNode{};
    node->identifierStr = idStr;
    node->varType = varType;
    node->initExpression = initExpr;
    node->id = ID++;
    return node;
}

VarDeclarationListNode* createVarDeclarationListNode(VarDeclarationNode* firstChild) {
    auto* node = new VarDeclarationListNode{};
    node->first = firstChild;
    node->last = firstChild;
    node->id = ID++;
    return node;
}
VarDeclarationListNode* addVarDeclarationToVarDeclarationList(VarDeclarationListNode* list, VarDeclarationNode* child) {
    list->last->next = child;
    list->last = child;
    return list;
}


    // ====== Statement ====== //

StatementNode* createEmptyStatementNode() {
    auto* stmt = new StatementNode{};
    stmt->type = StatementType::_EMPTY;
    stmt->id = ID++;
    return stmt;
}
StatementNode* createExpressionStatementNode(ExpressionNode* expr) {
    auto* stmt = new StatementNode{};
    stmt->type = StatementType::_EXPRESSION;
    stmt->expression = expr;
    stmt->id = ID++;
    return stmt;
}
StatementNode* createVarStatementNode(enum VarModifierType modifierType, VarDeclarationListNode* declList) {
    auto* node = new StatementNode{};
    node->type = StatementType::_VAR;
    node->modifierType = modifierType;
    node->declList = declList;
    node->id = ID++;
    return node;
}
StatementNode* createReturnStatementNode(ExpressionNode* expr) {
    auto* stmt = new StatementNode{};
    stmt->type = StatementType::_RETURN;
    stmt->expression = expr;
    stmt->id = ID++;
    return stmt;
}
StatementNode* createBlockStatementNode(StatementListNode* stmtList) {
    auto* stmt = new StatementNode{};
    stmt->type = StatementType::_BLOCK;
    stmt->stmtList = stmtList;
    stmt->id = ID++;
    return stmt;
}
StatementNode* createIfElseStatementNode(ExpressionNode* condition, StatementNode* ifBody, StatementNode* elseBody) {
    auto* stmt = new StatementNode{};
    stmt->type = StatementType::_CONDITION;
    stmt->expression = condition;
    stmt->ifBody = ifBody;
    stmt->elseBody = elseBody;
    stmt->id = ID++;
    return stmt;
}

StatementNode* createDoWhileStatementNode(StatementNode* body, ExpressionNode* condition) {
    auto* stmt = new StatementNode{};
    stmt->type = StatementType::_DOWHILE;
    stmt->iterationBody = body;
    stmt->expression = condition;
    stmt->id = ID++;
    return stmt;
}
StatementNode* createWhileStatementNode(ExpressionNode* condition, StatementNode* body) {
    auto* stmt = new StatementNode{};
    stmt->type = StatementType::_WHILE;
    stmt->iterationBody = body;
    stmt->expression = condition;
    stmt->id = ID++;
    return stmt;
}
StatementNode* createClassicForStatementNode(
    ExpressionNode* expr1, ExpressionNode* expr2, ExpressionNode* expr3, StatementNode* body
) {
    auto* stmt = new StatementNode{};
    stmt->type = StatementType::_FOR;
    stmt->iterationBody = body;
    stmt->expression = expr1;
    stmt->iterationExprAdd1 = expr2;
    stmt->iterationExprAdd2 = expr3;
    stmt->id = ID++;
    return stmt;
}
StatementNode* createClassicForWithVarDeclStatementNode(
    VarModifierType modifierType,
    VarDeclarationListNode* declList,
    ExpressionNode* expr2,
    ExpressionNode* expr3,
    StatementNode* body
) {
    auto* stmt = new StatementNode{};
    stmt->type = StatementType::_FOR;
    stmt->iterationBody = body;
    stmt->modifierType = modifierType;
    stmt->declList = declList;
    stmt->iterationExprAdd1 = expr2;
    stmt->iterationExprAdd2 = expr3;
    stmt->id = ID++;
    return stmt;
}
StatementNode* createForExprInExprStatementNode(ExpressionNode* expr1, ExpressionNode* expr2, StatementNode* body) {
    auto* stmt = new StatementNode{};
    stmt->type = StatementType::_FOR;
    stmt->iterationBody = body;
    stmt->expression = expr1;
    stmt->iterationExprAdd1 = expr2;
    stmt->id = ID++;
    return stmt;
}
StatementNode* createForVarDeclInExprStatementNode(
    VarModifierType modifierType, VarDeclarationNode* decl, ExpressionNode* expr, StatementNode* body
) {
    auto* stmt = new StatementNode{};
    stmt->type = StatementType::_FOR;
    stmt->iterationBody = body;
    stmt->modifierType = modifierType;
    stmt->decl = decl;
    stmt->expression = expr;
    stmt->id = ID++;
    return stmt;
}


    // ====== StatementList ====== //

StatementListNode* createStatementListNode(StatementNode* firstChild) {
    auto* node = new StatementListNode{};
    node->first = firstChild;
    node->last = firstChild;
    node->id = ID++;
    return node;
}

StatementListNode* addStatementToStatementList(StatementListNode* list, StatementNode* statement) {
    list->last->next = statement;
    list->last = statement;
    return list;
}


	// ====== Function declaration ====== //

FunctionDeclarationNode* createFunctionDeclarationNode(char* funcName, CallSignatureNode* callSignature, StatementListNode* body) {
    auto* node = new FunctionDeclarationNode{};
    node->funcName = funcName;
    node->callSignature = callSignature;
    node->body = body;
    node->id = ID++;
    return node;
}

CallSignatureNode* createCallSignatureNode(RequiredParameterListNode* params, TypeNode* returnType) {
    auto* node = new CallSignatureNode{};
    node->params = params;
    node->returnType = returnType;
    node->id = ID++;
    return node;
}

RequiredParameterListNode* createRequiredParameterListNode(RequiredParameterNode* firstChild) {
    auto* node = new RequiredParameterListNode{};
    node->first = firstChild;
    node->last = firstChild;
    node->id = ID++;
    return node;
}
RequiredParameterListNode* addRequiredParameterToRequiredParameterList(RequiredParameterListNode* list, RequiredParameterNode* child) {
    list->last->next = child;
    list->last = child;
    return list;
}

RequiredParameterNode* createRequiredParameterNode(char* paramName, TypeNode* paramType) {
    auto* node = new RequiredParameterNode{};
    node->paramName = paramName;
    node->paramType = paramType;
    node->id = ID++;
    return node;
}


    // ====== TSElementNode ====== //

TSElementNode* createElementFromStatement(StatementNode* stmt) {
    auto* node = new TSElementNode{};
    node->type = TSElementType::_STATEMENT_LIST;
    node->stmt = stmt;
    node->id = ID++;
    return node;
}
TSElementNode* createElementFromFuncDeclaration(FunctionDeclarationNode* funcDecl) {
    auto* node = new TSElementNode{};
    node->type = TSElementType::_FUNCTION;
    node->funcDecl = funcDecl;
    node->id = ID++;
    return node;
}


    // ====== TSElementListNode ====== //

TSElementListNode* createTSElementListNode(TSElementNode* elem) {
    auto* node = new TSElementListNode{};
    node->id = ID++;
    node->first = elem;
    node->last = elem;
    return node;
}

TSElementListNode* addTSElementNodeToList(TSElementListNode* elemList, TSElementNode* elem) {
    elemList->last->next = elem;
    elemList->last = elem;
    return elemList;
}

TSScriptNode* createTSScriptNode(TSElementListNode* elemList) {
    auto* node = new TSScriptNode{};
    node->id = ID++;
    node->elemList = elemList;
    return node;
}
