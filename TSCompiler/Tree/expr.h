#pragma once
#include <functional>

#include "node.h"
#include "type.h"

struct ClassElementNode;
struct VarDeclarationNode;
struct ExpressionListNode;

struct ExpressionNode final : Node
{
    enum class Type
    {
        _IDENTIFIER,

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

        _ASSIGN_TO_ARRAY_ELEMENT,
        _ASSIGN_TO_FIELD,

        _LESS,
        _GREAT,
        _EQUAL,
        _NOT_EQUAL,
        _LESS_EQUAL,
        _GREAT_EQUAL,

        _COMMA,
        _TERNARY,
        _INSTANCEOF,
        _IN,

        _ARRAY_EMPTY_ELEMENT,
        _ARRAY_CREATION,
        _ARRAY_ACCESS,
        _ARRAY_LENGTH,

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

    ExpressionNode *convertedFrom{};  // using for saving info after conversion
                                      // between node types
    TypeNode *exprType{};

    bool isLeftHand{0};

    ClassElementNode *actualMethodCall{};
    ClassElementNode *actualField{};
    VarDeclarationNode *actualVar{};

    std::string toString() const noexcept override { return "ExpressionNode"; }

    static ExpressionNode *fromId(const std::string value);
    static ExpressionNode *fromThis();
    static ExpressionNode *fromSuper();

    static ExpressionNode *fromIntLit(int value);
    static ExpressionNode *fromFloatLit(double value);
    static ExpressionNode *fromStringLit(const std::string value);
    static ExpressionNode *fromTrueLit();
    static ExpressionNode *fromFalseLit();
    static ExpressionNode *fromNullLit();
    static ExpressionNode *fromUndefinedLit();

    static ExpressionNode *fromUnaryExpr(Type type, ExpressionNode *fOp);
    static ExpressionNode *fromBinaryExpr(Type type, ExpressionNode *fOp,
                                          ExpressionNode *sOp);
    static ExpressionNode *fromTernaryExpr(ExpressionNode *fOp,
                                           ExpressionNode *sOp,
                                           ExpressionNode *tOp);

    static ExpressionNode *fromArrayAccessExpr(ExpressionNode *arr,
                                               ExpressionNode *index);
    static ExpressionNode *fromEmptyArrayElementExpr();

    static ExpressionNode *fromArrayLiteral(ExpressionListNode *params);

    static ExpressionNode *fromFuncCall(const std::string name,
                                        ExpressionListNode *params);

    static ExpressionNode *fromSuperCall(ExpressionListNode *params);

    static ExpressionNode *fromFieldAccess(ExpressionNode *obj,
                                           const std::string name);
    static ExpressionNode *fromMethodCall(ExpressionNode *obj,
                                          const std::string name,
                                          ExpressionListNode *params);

    static ExpressionNode *fromNew(const std::string name,
                                   ExpressionListNode *params);

    ExpressionNode *toASsignOnArrayElement() const;
    ExpressionNode *toAssignOnField() const;

    ExpressionNode *toRTLMethodCall() const;

    void applyToAllChildren(
        const std::function<ExpressionNode *(ExpressionNode *)> &mapFunction);
    void callForAllChildren(
        const std::function<void(ExpressionNode *)> &function) const;

    bool isBinary()
    {
        switch (this->type)
        {
        case Type::_PLUS:
        case Type::_MINUS:
        case Type::_MUL:
        case Type::_DIV:
        case Type::_LOGICAL_OR:
        case Type::_LOGICAL_AND:
        case Type::_ASSIGN:
        case Type::_ASSIGN_PLUS:
        case Type::_ASSIGN_MINUS:
        case Type::_ASSIGN_MUL:
        case Type::_ASSIGN_DIV:
        case Type::_ASSIGN_LOGICAL_OR:
        case Type::_ASSIGN_LOGICAL_AND:
        case Type::_LESS:
        case Type::_GREAT:
        case Type::_EQUAL:
        case Type::_NOT_EQUAL:
        case Type::_LESS_EQUAL:
        case Type::_GREAT_EQUAL:
        case Type::_COMMA:
        case Type::_INSTANCEOF:
        case Type::_IN:
            return true;
        default:
            return false;
        }
    }

    bool isUnary()
    {
        switch (this->type)
        {
        case Type::_UPLUS:
        case Type::_UMINUS:
        case Type::_NOT:
        case Type::_PREF_INCREMENT:
        case Type::_PREF_DECREMENT:
        case Type::_POST_INCREMENT:
        case Type::_POST_DECREMENT:
            return true;
        default:
            return false;
        }
    }

    bool isLogical()
    {
        switch (this->type)
        {
        case Type::_NOT:
        case Type::_LOGICAL_OR:
        case Type::_LOGICAL_AND:
            return true;
        default:
            return false;
        }
    }

    bool isComparsion()
    {
        switch (this->type)
        {
        case Type::_LESS:
        case Type::_GREAT:
        case Type::_EQUAL:
        case Type::_NOT_EQUAL:
        case Type::_LESS_EQUAL:
        case Type::_GREAT_EQUAL:
            return true;
        default:
            return false;
        }
    }

    std::string toStringType()
    {
        switch (this->type)
        {
        case Type::_IDENTIFIER:
            return "identExpr";
        case Type::_INT_LIT:
            return "intLit";
        case Type::_FLOAT_LIT:
            return "floatLit";
        case Type::_STRING_LIT:
            return "stringLit";
        case Type::_BOOLEAN_LIT:
            return "booleanLit";
        case Type::_NULL_LIT:
            return "nullLit";
        case Type::_UNDEFINED_LIT:
            return "undefinedLit";
        case Type::_PREF_INCREMENT:
            return "pref_increment";
        case Type::_PREF_DECREMENT:
            return "pref_decrement";
        case Type::_POST_INCREMENT:
            return "post_increment";
        case Type::_POST_DECREMENT:
            return "post_decrement";
        case Type::_PLUS:
            return "+";
        case Type::_MINUS:
            return "-";
        case Type::_MUL:
            return "*";
        case Type::_DIV:
            return "/";
        case Type::_UPLUS:
            return "+";
        case Type::_UMINUS:
            return "-";
        case Type::_NOT:
            return "!";
        case Type::_LOGICAL_OR:
            return "||";
        case Type::_LOGICAL_AND:
            return "&&";
        case Type::_ASSIGN:
            return "=";
        case Type::_ASSIGN_PLUS:
            return "+=";
        case Type::_ASSIGN_MINUS:
            return "-=";
        case Type::_ASSIGN_MUL:
            return "*=";
        case Type::_ASSIGN_DIV:
            return "/=";
        case Type::_ASSIGN_LOGICAL_OR:
            return "||=";
        case Type::_ASSIGN_LOGICAL_AND:
            return "&&=";
        case Type::_ASSIGN_TO_ARRAY_ELEMENT:
            return "[]=";
        case Type::_ASSIGN_TO_FIELD:
            return ".=";
        case Type::_LESS:
            return "<";
        case Type::_GREAT:
            return ">";
        case Type::_EQUAL:
            return "==";
        case Type::_NOT_EQUAL:
            return "!=";
        case Type::_LESS_EQUAL:
            return "<=";
        case Type::_GREAT_EQUAL:
            return ">=";
        case Type::_COMMA:
            return ",";
        case Type::_TERNARY:
            return "?:";
        case Type::_INSTANCEOF:
            return "instanceof";
        case Type::_IN:
            return "in";
        case Type::_ARRAY_EMPTY_ELEMENT:
            return "array_empty_element";
        case Type::_ARRAY_CREATION:
            return "array_creation";
        case Type::_ARRAY_ACCESS:
            return "array_access";
        case Type::_FUNC_CALL:
            return "func_call";
        case Type::_SUPER_CALL:
            return "super_call";
        case Type::_FIELD_ACCESS:
            return "field_access";
        case Type::_METHOD_CALL:
            return "method_call";
        case Type::_NEW:
            return "new";
        }
        return "";
    }
};

struct RequiredParameterListNode;
struct ExpressionListNode final : NodeList<ExpressionListNode, ExpressionNode>
{
    using NodeList<ExpressionListNode, ExpressionNode>::NodeList;

    std::string toString() const noexcept override
    {
        return "ExpressionListNode";
    }

    static ExpressionListNode *fromExpression(ExpressionNode *node);
    static ExpressionListNode *fromRequiredParams(
        RequiredParameterListNode *node);
};
