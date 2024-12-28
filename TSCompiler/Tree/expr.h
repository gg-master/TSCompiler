#pragma once
#include "node.h"

struct ExpressionListNode;

struct ExpressionNode final : Node
{
    enum class Type
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
        _METHOD_CALL,
        _NEW,
    } type{};

    int intValue{};
    int boolValue{};
    double floatValue{};
    std::string stringValue{};

    // using for function, methods and variables
    std::string identifierString{};

    ExpressionNode *firstOperand{};
    ExpressionNode *secondOperand{};
    ExpressionNode *thirdOperand{};

    ExpressionListNode *params{};

    std::string toString() const noexcept override { return "ExpressionNode"; }

    static ExpressionNode *fromId(const std::string value);
    static ExpressionNode *fromThis();

    static ExpressionNode *fromIntLit(int value);
    static ExpressionNode *fromFloatLit(double value);
    static ExpressionNode *fromStringLit(const std::string value);
    static ExpressionNode *fromTrueLit();
    static ExpressionNode *fromFalseLit();
    static ExpressionNode *fromNullLit();
    static ExpressionNode *fromUndefinedLit();

    static ExpressionNode *fromUnaryExpr(Type type, ExpressionNode *fOp);
    static ExpressionNode *fromBinaryExpr(Type type, ExpressionNode *fOp, ExpressionNode *sOp);
    static ExpressionNode *fromTernaryExpr(ExpressionNode *fOp, ExpressionNode *sOp,
                                           ExpressionNode *tOp);

    static ExpressionNode *fromArrayAccessExpr(ExpressionNode *arr, ExpressionNode *index);
    static ExpressionNode *fromEmptyArrayElementExpr();

    static ExpressionNode *fromArrayLiteral(ExpressionListNode *params);

    static ExpressionNode *fromFuncCall(const std::string name, ExpressionListNode *params);

    static ExpressionNode *fromSuperCall(ExpressionListNode *params);

    static ExpressionNode *fromFieldAccess(ExpressionNode *obj, const std::string name);
    static ExpressionNode *fromMethodCall(ExpressionNode *obj, const std::string name,
                                          ExpressionListNode *params);

    static ExpressionNode *fromNew(const std::string name, ExpressionListNode *params);
};

struct ExpressionListNode final : NodeList<ExpressionListNode, ExpressionNode>
{
    using NodeList<ExpressionListNode, ExpressionNode>::NodeList;

    std::string toString() const noexcept override { return "ExpressionListNode"; }

    static ExpressionListNode *fromExpression(ExpressionNode *node);

    void merge(ExpressionListNode *node)
    {
        auto &leftSeq = this->GetSeq();
        auto &rightSeq = node->GetSeq();
        leftSeq.insert(leftSeq.end(), rightSeq.begin(), rightSeq.end());
    }
};
