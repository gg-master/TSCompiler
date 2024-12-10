#pragma once
#include <string>

	// ====== Expression ====== //

enum class ExpressionType 
{
	_IDENTIFIER,
	_BOOLEAN_LIT,
	_INT_LIT,
	_FLOAT_LIT,
	_STRING_LIT,
	_NULL_LIT,
	
	_UPLUS,
	_UMINUS,
	
	_PREF_INCREMENT,
	_PREF_DECREMENT,
	_POST_INCREMENT,
	_POST_DECREMENT,

	_PLUS,
	_MINUS,
	_DIV,
	_MUL,

	_LESS,
	_GREAT,
	_EQUAL,
	_NOT_EQUAL,
	_STRICT_EQUAL,
	_STRICT_NOT_EQUAL,
	_LESS_EQUAL,
	_GREAT_EQUAL,

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

	_COMMA,
	_BRACKETS,
	_FIELD_ACCESS,
	_METHOD_ACCESS,
	_FUNC_CALL,
	
	_THIS,
	_SUPER,

	_ARRAY_EMPTY_ELEMENT,
	_ARRAY_CREATION,
	_ARRAY_ACCESS,

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


	// ====== Statement ====== //

enum class StatementType
{
	_EMPTY,
	_EXPRESSION,
	_VAR,
	_WHILE,
	_DOWHILE,
	_FOR,
	_RETURN,
};

struct StatementNode
{
	int id;

	enum StatementType type;

	struct ExpressionNode* expression;
	struct VarStatementNode* varStmt;

	struct StatementNode * next;
};

struct StatementListNode
{
	int id;

	struct StatementNode* first;
	struct StatementNode* last;
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

struct VarStatementNode
{
	int id;

	enum VarModifierType modifierType;

	struct VarDeclarationListNode* declList;
};

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