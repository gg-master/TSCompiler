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

    // ====== Statement ====== //

StatementNode* createStatementFromExpression(ExpressionNode* expr) {
    auto* stmt = new StatementNode{};
    stmt->type = StatementType::_EXPRESSION;
    stmt->expression = expr;
    stmt->id = ID++;
    return stmt;
}

StatementNode* createStatementFromVarStatement(VarStatementNode* varStmt) {
    auto* stmt = new StatementNode{};
    stmt->type = StatementType::_VAR;
    stmt->varStmt = varStmt;
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

VarStatementNode* createVarStatementNode(enum VarModifierType modifierType, VarDeclarationListNode* declList) {
    auto* node = new VarStatementNode{};
    node->modifierType = modifierType;
    node->declList = declList;
    node->id = ID++;
    return node;
}

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


    // ====== TSElementNode ====== //

TSElementNode* createElementFromStatement(StatementNode* stmt) {
    auto* node = new TSElementNode{};
    node->stmt = stmt;
    node->type = TSElementType::_STATEMENT_LIST;
    node->next = NULL;
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
