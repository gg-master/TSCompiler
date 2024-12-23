#pragma once
#include <string>

// ====== Expression ====== //

enum class ExpressionType {
    _IDENTIFIER,
    _THIS,

    _INT_LIT,
    _FLOAT_LIT,
    _STRING_LIT,
    _BOOLEAN_LIT,
    _NULL_LIT,
	_UNDEFINED_LIT,

    _PREF_INCREMENT,
    _PREF_DECREMENT,
    _POST_INCREMENT,
    _POST_DECREMENT,

    _PLUS,
    _MINUS,
    _MUL,
    _DIV,

    _UPLUS,
    _UMINUS,

    _NOT,
    _LOGICAL_OR,
    _LOGICAL_AND,

    _ASSIGN,
    _ASSIGN_PLUS,
    _ASSIGN_MINUS,
    _ASSIGN_MUL,
    _ASSIGN_DIV,
    _ASSIGN_LOGICAL_OR,
    _ASSIGN_LOGICAL_AND,

    _LESS,
    _GREAT,
    _EQUAL,
    _NOT_EQUAL,
    _STRICT_EQUAL,
    _STRICT_NOT_EQUAL,
    _LESS_EQUAL,
    _GREAT_EQUAL,

    _COMMA,
    _TERNARY,
    _INSTANCEOF,
    _IN,

    _BRACKETS,

    _ARRAY_EMPTY_ELEMENT,
    _ARRAY_CREATION,
    _ARRAY_ACCESS,

    _FUNC_CALL,

    _SUPER_CALL,

    _FIELD_ACCESS,
    _METHOD_ACCESS,
    _NEW,
};

enum class BaseLiteral {
    _FROM_INT,
    _FROM_FLOAT,
    _FROM_BOOLEAN,
    _FROM_STRING,
    _FROM_NULL,
    _FROM_UNDEFINED
};

struct ExpressionNode {
    int id;

    int intValue;
    int boolValue;
    double floatValue;
    char *stringValue;

    // using for function, methods and variables
    char *identifierString;

    enum ExpressionType type;

    struct ExpressionNode *firstOperand;
    struct ExpressionNode *secondOperand;
    struct ExpressionNode *thirdOperand;

    struct ExpressionListNode *params;

    enum BaseLiteral fromLit;
    // using for ExpressionListNode
    struct ExpressionNode *next;
};

struct ExpressionListNode {
    int id;

    struct ExpressionNode *first;
    struct ExpressionNode *last;
};

// ====== Types ====== //

enum class TypeType {
    _NUMBER,
    _STRING,
    _BOOLEAN,
    _UNDEFINED,
    _VOID,
    _NULL,

    _ARRAY,
    _TUPLE,

    _USER_TYPE,
};

struct TupleTypeNode;

struct TypeNode {
    int id;

    enum TypeType type;

    struct TypeNode *arrayType;
    struct TupleTypeNode *tupleNode;

    char *userTypeName;

    // using for TupleType
    struct TypeNode *next;
};

struct TupleTypeNode {
    int id;

    struct TypeNode *first;
    struct TypeNode *last;
};

// ====== VarDeclaration ====== //

enum class VarModifierType {
    _LET,
    _VAR,
    _CONST,
};

inline std::string ToString(VarModifierType type) {
    switch (type) {
    case VarModifierType::_LET:
        return "let";
    case VarModifierType::_VAR:
        return "var";
    case VarModifierType::_CONST:
        return "const";
    default:
        return "";
    }
}

struct VarDeclarationNode {
    int id;

    char *identifierStr;
    struct TypeNode *varType;
    struct ExpressionNode *initExpression;

    struct VarDeclarationNode *next;
};

struct VarDeclarationListNode {
    int id;

    struct VarDeclarationNode *first;
    struct VarDeclarationNode *last;
};

// ====== Statement ====== //

enum class StatementType {
    _EMPTY,
    _EXPRESSION,
    _VAR,
    _IFELSE,
    _WHILE,
    _DOWHILE,
    _FOR,
    _RETURN,
    _BLOCK,
};

struct StatementListNode;

struct StatementNode {
    int id;

    enum StatementType type;

    // exprStmt, returnStmt, conditшon-head
    struct ExpressionNode *expression;

    // varStmt, iterations
    enum class VarModifierType modifierType;
    struct VarDeclarationListNode *declList;
    struct VarDeclarationNode *decl;

    // blockStmt
    struct StatementListNode *stmtList;

    // condition
    struct StatementNode *ifBody;
    struct StatementNode *elseBody;

    // iterations
    struct StatementNode *iterationBody;
    struct ExpressionNode *iterationExprAdd1;
    struct ExpressionNode *iterationExprAdd2;

    struct StatementNode *next;
};

struct StatementListNode {
    int id;

    struct StatementNode *first;
    struct StatementNode *last;
};

// ====== Function declaration ====== //

struct FunctionDeclarationNode {
    int id;

    char *funcName;
    struct RequiredParameterListNode *params;
    struct TypeNode *returnType;

    struct StatementListNode *body;
};

struct RequiredParameterNode {
    int id;

    char *paramName;
    struct TypeNode *paramType;

    struct RequiredParameterNode *next;
};

struct RequiredParameterListNode {
    int id;

    struct RequiredParameterNode *first;
    struct RequiredParameterNode *last;
};

// ====== Class declaration ====== //

enum class ClassElementType {
    _CONSTRUCTOR,
    _PROPERTY,
    _METHOD
};

struct ClassElementNode {
    int id;

    enum ClassElementType type;

    char *name;
    struct TypeNode *propertyAndReturnType;

    struct ExpressionNode *expression;

    struct RequiredParameterListNode *params;
    struct StatementListNode *methodBody;

    struct ClassElementNode *next;
};

struct ClassElementListNode {
    int id;

    struct ClassElementNode *first;
    struct ClassElementNode *last;
};

struct ClassDeclarationNode {
    int id;

    char *className;
    char *heritageName;

    struct ClassElementListNode *body;
};

// ====== TS Script ====== //

enum class TSElementType {
    _CLASS,
    _FUNCTION,
    _STATEMENT,
};

struct TSElementNode {
    int id;

    enum TSElementType type;

    struct StatementNode *stmt;
    struct FunctionDeclarationNode *funcDecl;
    struct ClassDeclarationNode *classDecl;

    struct TSElementNode *next;
};

struct TSElementListNode {
    int id;

    struct TSElementNode *first;
    struct TSElementNode *last;
};

struct TSScriptNode {
    int id;

    struct TSElementListNode *elemList;
};