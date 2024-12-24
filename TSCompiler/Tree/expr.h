#pragma once
#include "node.h"

enum class ExpressionType
{
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

    _ARRAY_EMPTY_ELEMENT,
    _ARRAY_CREATION,
    _ARRAY_ACCESS,

    _FUNC_CALL,

    _SUPER_CALL,

    _FIELD_ACCESS,
    _METHOD_ACCESS,
    _NEW,
};

enum class BaseLiteral
{
    _FROM_INT,
    _FROM_FLOAT,
    _FROM_BOOLEAN,
    _FROM_STRING,
    _FROM_NULL,
    _FROM_UNDEFINED
};

struct ExpressionNode final : Node
{
    std::string_view name() const noexcept override { return "ExpressionNode"; }

    int intValue;
    int boolValue;
    double floatValue;
    char *stringValue;

    // using for function, methods and variables
    char *identifierString;

    ExpressionType type{};

    ExpressionNode *firstOperand{};
    ExpressionNode *secondOperand{};
    ExpressionNode *thirdOperand{};

    ExpressionListNode *params{};

    enum BaseLiteral fromLit;
};

struct ExpressionListNode final : NodeList<ExpressionListNode, ExpressionNode>
{
    using NodeList<ExpressionListNode, ExpressionNode>::NodeList;

    std::string_view name() const noexcept override { return "ExpressionListNode"; }
};