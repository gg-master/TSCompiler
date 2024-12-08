#pragma once

enum class ExpressionType 
{
	_IDENTIFIER,
	_BOOLEAN_LIT,
	_INT_LIT,
	_FLOAT_LIT,
	_STRING_LIT,
	
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

	struct ExpressionNode* leftOperand;
	struct ExpressionNode* rightOperand;

	struct ExpressionNode* nextExpression;
};

struct ExpressionListNode
{
	int id;

	struct ExpressionNode* first;
	struct ExpressionNode* last;
};

enum class StatementType
{
	_EXPRESSION,
	_EMPTY,
	_RETURN,
	_VAR,
	_WHILE,
	_DOWHILE,
	_FOR,
};

struct StatementNode
{
	int id;

	enum StatementType type;

	struct ExpressionNode* expression;

	struct StatementNode * next;
};

struct StatementListNode
{
	int id;

	struct StatementNode* first;
	struct StatementNode* last;
};

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