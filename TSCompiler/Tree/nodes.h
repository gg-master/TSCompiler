#pragma once
#include <string>

	// ====== Expression ====== //

enum class ExpressionType 
{
	_IDENTIFIER, // Сделано

	_PLUS, // Сделано
	_MINUS, // Сделано
	_MUL, // Сделано
	_DIV, // Сделано
	_LESS, // Сделано
	_GREAT, // Сделано

	_UPLUS, // Сделано
	_UMINUS, // Сделано

	_NOT, // Сделано
	_LOGICAL_OR, // Сделано
	_LOGICAL_AND, // Сделано

	_COMMA, // Сделано
	_BRACKETS, // Сделано

	_THIS, // Сделано
	_SUPER, // Сделано
	_FUNC_CALL, // Сделано

	_ARRAY_EMPTY_ELEMENT, // Сделано
	_ARRAY_CREATION, // Сделано
	_ARRAY_ACCESS,

	_PREF_INCREMENT, // Сделано
	_PREF_DECREMENT, // Сделано
	_POST_INCREMENT, // Сделано
	_POST_DECREMENT, // Сделано

	_BOOLEAN_LIT,
	_INT_LIT,
	_FLOAT_LIT,
	_STRING_LIT,
	_NULL_LIT,

	_ASSIGN,
	_ASSIGN_PLUS,
	_ASSIGN_MINUS,
	_ASSIGN_MUL,
	_ASSIGN_DIV,
	_ASSIGN_LOGICAL_OR,
	_ASSIGN_LOGICAL_AND,

	_EQUAL,
	_NOT_EQUAL,
	_STRICT_EQUAL,
	_STRICT_NOT_EQUAL,
	_LESS_EQUAL,
	_GREAT_EQUAL,

	_FIELD_ACCESS,
	_METHOD_ACCESS,

	_NEW,
};

struct ExpressionNode
{
	int id;

	int intValue;
	int boolValue;
	double floatValue;
	char* stringValue;

	// using for function, methods and variables
	char* identifierString;

	enum ExpressionType type;

	struct ExpressionNode* firstOperand;
	struct ExpressionNode* secondOperand;
	struct ExpressionNode* thirdOperand;

	// using for ExpressionListNode
	struct ExpressionNode* next;

	struct ExpressionListNode* params;
};

struct ExpressionListNode
{
	int id;

	struct ExpressionNode* first;
	struct ExpressionNode* last;
};


	// ====== Types ====== //

enum class TypeType
{
	_NUMBER,
	_STRING,
	_BOOLEAN,
	_UNDEFINED,
	_VOID,
	_NULL,

	_ARRAY,
	_TUPLE,
};

struct TupleTypeNode;

struct TypeNode
{
	int id;

	enum TypeType type;

	struct TypeNode* arrayType;
	struct TupleTypeNode* tupleNode;

	// using for TupleType
	struct TypeNode* next;
};

struct TupleTypeNode
{
	int id;

	struct TypeNode* first;
	struct TypeNode* last;
};


	// ====== VarDeclaration ====== //

enum class VarModifierType
{
	_LET,
	_VAR,
	_CONST,
};

inline std::string ToString(VarModifierType type) {
	switch (type)
	{
	case VarModifierType::_LET: return "let";
	case VarModifierType::_VAR: return "var";
	case VarModifierType::_CONST: return "const";
	default:
		return "";
	}
}

struct VarDeclarationNode
{
	int id;

	char* identifierStr;
	struct TypeNode* varType;
	struct ExpressionNode* initExpression;
	
	struct VarDeclarationNode* next;
};

struct VarDeclarationListNode
{
	int id;

	struct VarDeclarationNode* first;
	struct VarDeclarationNode* last;
};


	// ====== Statement ====== //

enum class StatementType
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
};

struct StatementListNode;

struct StatementNode
{
	int id;

	enum StatementType type;
	
	// exprStmt, returnStmt, conditшon-head
	struct ExpressionNode* expression;

	// varStmt, iterations
	enum class VarModifierType modifierType;
	struct VarDeclarationListNode* declList;
	struct VarDeclarationNode* decl;

	// blockStmt
	struct StatementListNode* stmtList;

	// condition
	struct StatementNode* ifBody;
	struct StatementNode* elseBody;

	// iterations
	struct StatementNode* iterationBody;
	struct ExpressionNode* iterationExprAdd1;
	struct ExpressionNode* iterationExprAdd2;

	struct StatementNode* next;
};

struct StatementListNode
{
	int id;

	struct StatementNode* first;
	struct StatementNode* last;
};


	// ====== Function declaration ====== //

struct FunctionDeclarationNode
{
	int id;

	char* funcName;
	struct RequiredParameterListNode* params;
	struct TypeNode* returnType;

	struct StatementListNode* body;
};

struct RequiredParameterNode
{
	int id;

	char* paramName;
	struct TypeNode* paramType;

	struct RequiredParameterNode* next;
};

struct RequiredParameterListNode
{
	int id;

	struct RequiredParameterNode* first;
	struct RequiredParameterNode* last;
};


	// ====== Class declaration ====== //

enum class ClassElementType
{
	_CONSTRUCTOR,
	_PROPERTY,
	_METHOD,
	_GETTER,
	_SETTER,
};

struct ClassElementNode
{
	int id;

	enum ClassElementType type;

	char* name;
	struct TypeNode* propertyAndReturnType;

	struct ExpressionNode* expression;

	struct RequiredParameterListNode* params;
	struct StatementListNode* methodBody;

	struct ClassElementNode* next;
};

struct ClassElementListNode
{
	int id;

	struct ClassElementNode* first;
	struct ClassElementNode* last;
};

struct ClassDeclarationNode
{
	int id;

	char* className;
	char* heritageName;

	struct ClassElementListNode* body;
};


	// ====== TS Script ====== //

enum class TSElementType
{
	_CLASS,
	_FUNCTION,
	_STATEMENT_LIST,
};

struct TSElementNode
{
	int id;

	enum TSElementType type;

	struct StatementNode* stmt;
	struct FunctionDeclarationNode* funcDecl;
	struct ClassDeclarationNode* classDecl;

	struct TSElementNode* next;
};

struct TSElementListNode
{
	int id;

	struct TSElementNode* first;
	struct TSElementNode* last;
};

struct TSScriptNode
{
	int id;

	struct TSElementListNode* elemList;
};