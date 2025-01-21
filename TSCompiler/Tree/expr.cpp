#include "expr.h"

#include "../Semantic/jvm_class.h"
#include "func.h"

ExpressionNode *ExpressionNode::fromId(const std::string value)
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_IDENTIFIER;
    node->identifierString = value;
    return node;
}
ExpressionNode *ExpressionNode::fromThis()
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_IDENTIFIER;
    node->identifierString = "this";
    return node;
}
ExpressionNode *ExpressionNode::fromSuper()
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_IDENTIFIER;
    node->identifierString = "super";
    return node;
}

ExpressionNode *ExpressionNode::fromIntLit(int value)
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_INT_LIT;
    node->intValue = value;
    return node;
}
ExpressionNode *ExpressionNode::fromFloatLit(double value)
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_FLOAT_LIT;
    node->floatValue = value;
    return node;
}
ExpressionNode *ExpressionNode::fromStringLit(const std::string value)
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_STRING_LIT;
    node->stringValue = value;
    return node;
}
ExpressionNode *ExpressionNode::fromTrueLit()
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_BOOLEAN_LIT;
    node->boolValue = 1;
    return node;
}
ExpressionNode *ExpressionNode::fromFalseLit()
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_BOOLEAN_LIT;
    node->boolValue = 0;
    return node;
}
ExpressionNode *ExpressionNode::fromNullLit()
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_NULL_LIT;
    return node;
}
ExpressionNode *ExpressionNode::fromUndefinedLit()
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_UNDEFINED_LIT;
    return node;
}

ExpressionNode *ExpressionNode::fromUnaryExpr(Type type, ExpressionNode *fOp)
{
    auto *node = new ExpressionNode{};
    node->type = type;
    node->firstOperand = fOp;
    return node;
}
ExpressionNode *ExpressionNode::fromBinaryExpr(Type type, ExpressionNode *fOp,
                                               ExpressionNode *sOp)
{
    auto *node = new ExpressionNode{};
    node->type = type;
    node->firstOperand = fOp;
    node->secondOperand = sOp;
    return node;
}
ExpressionNode *ExpressionNode::fromTernaryExpr(ExpressionNode *fOp,
                                                ExpressionNode *sOp,
                                                ExpressionNode *tOp)
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_TERNARY;
    node->firstOperand = fOp;
    node->secondOperand = sOp;
    node->thirdOperand = tOp;
    return node;
}

ExpressionNode *ExpressionNode::fromArrayAccessExpr(ExpressionNode *arr,
                                                    ExpressionNode *index)
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_ARRAY_ACCESS;
    node->firstOperand = arr;
    node->secondOperand = index;
    return node;
}
ExpressionNode *ExpressionNode::fromEmptyArrayElementExpr()
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_ARRAY_EMPTY_ELEMENT;
    return node;
}

ExpressionNode *ExpressionNode::fromArrayLiteral(ExpressionListNode *params)
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_ARRAY_CREATION;

    // removing last empty array element
    if (!params->GetSeq().empty() &&
        params->GetSeq().back()->type ==
            ExpressionNode::Type::_ARRAY_EMPTY_ELEMENT)
    {
        auto &seq = params->GetSeq();
        delete seq.back();
        seq.pop_back();
    }
    node->params = params;
    return node;
}

ExpressionNode *ExpressionNode::fromFuncCall(const std::string name,
                                             ExpressionListNode *params)
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_FUNC_CALL;
    node->identifierString = name;
    node->params = params;
    return node;
}

ExpressionNode *ExpressionNode::fromSuperCall(ExpressionListNode *params)
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_SUPER_CALL;
    node->params = params;
    return node;
}
ExpressionNode *ExpressionNode::fromFieldAccess(ExpressionNode *obj,
                                                const std::string name)
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_FIELD_ACCESS;
    node->firstOperand = obj;
    node->identifierString = name;
    return node;
}
ExpressionNode *ExpressionNode::fromMethodCall(ExpressionNode *obj,
                                               const std::string name,
                                               ExpressionListNode *params)
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_METHOD_CALL;
    node->firstOperand = obj;
    node->identifierString = name;
    node->params = params;
    return node;
}

ExpressionNode *ExpressionNode::fromNew(const std::string name,
                                        ExpressionListNode *params)
{
    auto *node = new ExpressionNode{};
    node->type = ExpressionNode::Type::_NEW;
    node->identifierString = name;
    node->params = params;
    return node;
}

ExpressionListNode *ExpressionListNode::fromExpression(ExpressionNode *node)
{
    ExpressionListNode *leftExprList = nullptr;
    ExpressionListNode *rightExprList = nullptr;

    if (node == nullptr)
    {
        return new ExpressionListNode{};
    }
    switch (node->type)
    {
    case ExpressionNode::Type::_COMMA:
        leftExprList = ExpressionListNode::fromExpression(node->firstOperand);
        rightExprList = ExpressionListNode::fromExpression(node->secondOperand);

        if (rightExprList && !rightExprList->GetSeq().empty())
        {
            auto &leftSeq = leftExprList->GetSeq();
            auto &rightSeq = rightExprList->GetSeq();
            leftSeq.insert(leftSeq.end(), rightSeq.begin(), rightSeq.end());
        }
        delete rightExprList;
        return leftExprList;
    default:
        auto *list = new ExpressionListNode{};
        list->add(node);
        return list;
    }
}

ExpressionListNode *ExpressionListNode::fromRequiredParams(
    RequiredParameterListNode *node)
{
    auto list = ExpressionListNode::makeEmpty();
    for (RequiredParameterNode *param : node->GetSeq())
    {
        list->add(ExpressionNode::fromId(param->paramName));
    }
    return list;
}

ExpressionNode *ExpressionNode::toAssignOnArrayElement() const
{
    if (type != Type::_ASSIGN || firstOperand->type != Type::_ARRAY_ACCESS)
        return nullptr;

    auto *assign = new ExpressionNode{};
    assign->type = Type::_ASSIGN_TO_ARRAY_ELEMENT;

    assign->firstOperand = firstOperand->firstOperand;
    assign->secondOperand = firstOperand->secondOperand;
    assign->thirdOperand = secondOperand;
    return assign;
}

ExpressionNode *ExpressionNode::toAssignOnField() const
{
    if (type != Type::_ASSIGN || firstOperand->type != Type::_FIELD_ACCESS ||
        !firstOperand->actualField)
        return nullptr;

    auto *assign = new ExpressionNode{};
    assign->type = Type::_ASSIGN_TO_FIELD;

    assign->firstOperand = firstOperand->firstOperand;
    assign->secondOperand = secondOperand;

    assign->identifierString = identifierString;

    assign->actualField = firstOperand->actualField;

    return assign;
}

ExpressionNode *ExpressionNode::toRTLMethodCall() const
{
    switch (type)
    {
    case Type::_PLUS:
        return fromMethodCall(firstOperand, "plus",
                              new ExpressionListNode(secondOperand));
    case Type::_MINUS:
        return fromMethodCall(firstOperand, "minus",
                              new ExpressionListNode(secondOperand));
    case Type::_MUL:
        return fromMethodCall(firstOperand, "mul",
                              new ExpressionListNode(secondOperand));
    case Type::_DIV:
        return fromMethodCall(firstOperand, "div",
                              new ExpressionListNode(secondOperand));
    case Type::_UPLUS:
        return fromMethodCall(firstOperand, "uPlus",
                              ExpressionListNode::makeEmpty());
    case Type::_UMINUS:
        return fromMethodCall(firstOperand, "uMinus",
                              ExpressionListNode::makeEmpty());
    case Type::_LESS:
        return fromMethodCall(firstOperand, "less",
                              new ExpressionListNode(secondOperand));
    case Type::_GREAT:
        return fromMethodCall(firstOperand, "great",
                              new ExpressionListNode(secondOperand));
    case Type::_EQUAL:
        return fromMethodCall(firstOperand, "equal",
                              new ExpressionListNode(secondOperand));
    case Type::_NOT_EQUAL:
        return fromMethodCall(firstOperand, "notEqual",
                              new ExpressionListNode(secondOperand));
    case Type::_LESS_EQUAL:
        return fromMethodCall(firstOperand, "lessEqual",
                              new ExpressionListNode(secondOperand));
    case Type::_GREAT_EQUAL:
        return fromMethodCall(firstOperand, "greatEqual",
                              new ExpressionListNode(secondOperand));
    case Type::_NOT:
        return fromMethodCall(
            fromNew("Boolean", new ExpressionListNode(firstOperand)), "not",
            ExpressionListNode::makeEmpty());

    case Type::_LOGICAL_OR:
        return fromTernaryExpr(firstOperand, firstOperand, secondOperand);

    case Type::_LOGICAL_AND:
        return fromTernaryExpr(
            fromUnaryExpr(Type::_NOT, firstOperand)->toRTLMethodCall(),
            firstOperand, secondOperand);

    case Type::_ASSIGN_PLUS:
        return fromBinaryExpr(
            Type::_ASSIGN, firstOperand,
            fromBinaryExpr(Type::_PLUS, firstOperand, secondOperand)
                ->toRTLMethodCall());
    case Type::_ASSIGN_MINUS:
        return fromBinaryExpr(
            Type::_ASSIGN, firstOperand,
            fromBinaryExpr(Type::_MINUS, firstOperand, secondOperand)
                ->toRTLMethodCall());
    case Type::_ASSIGN_MUL:
        return fromBinaryExpr(
            Type::_ASSIGN, firstOperand,
            fromBinaryExpr(Type::_MUL, firstOperand, secondOperand)
                ->toRTLMethodCall());
    case Type::_ASSIGN_DIV:
        return fromBinaryExpr(
            Type::_ASSIGN, firstOperand,
            fromBinaryExpr(Type::_DIV, firstOperand, secondOperand)
                ->toRTLMethodCall());
    case Type::_ASSIGN_LOGICAL_OR:
        return fromBinaryExpr(
            Type::_ASSIGN, firstOperand,
            fromBinaryExpr(Type::_LOGICAL_OR, firstOperand, secondOperand)
                ->toRTLMethodCall());
    case Type::_ASSIGN_LOGICAL_AND:
        return fromBinaryExpr(
            Type::_ASSIGN, firstOperand,
            fromBinaryExpr(Type::_LOGICAL_AND, firstOperand, secondOperand)
                ->toRTLMethodCall());
    default:
        break;
    }
    return nullptr;
}

void ExpressionNode::applyToAllChildren(
    const std::function<ExpressionNode *(ExpressionNode *)> &mapFunction)
{
    if (firstOperand)
    {
        firstOperand = mapFunction(firstOperand);
        firstOperand->applyToAllChildren(mapFunction);
    }
    if (secondOperand)
    {
        secondOperand = mapFunction(secondOperand);
        secondOperand->applyToAllChildren(mapFunction);
    }
    if (thirdOperand)
    {
        thirdOperand = mapFunction(thirdOperand);
        thirdOperand->applyToAllChildren(mapFunction);
    }
    if (params)
    {
        for (auto &expr : params->GetSeq())
        {
            expr = mapFunction(expr);
            expr->applyToAllChildren(mapFunction);
        }
    }
}

void ExpressionNode::callForAllChildren(
    const std::function<void(ExpressionNode *)> &function) const
{
    if (firstOperand)
    {
        function(firstOperand);
        firstOperand->callForAllChildren(function);
    }
    if (secondOperand)
    {
        function(secondOperand);
        secondOperand->callForAllChildren(function);
    }
    if (thirdOperand)
    {
        function(thirdOperand);
        thirdOperand->callForAllChildren(function);
    }
    if (params)
    {
        for (auto &expr : params->GetSeq())
        {
            function(expr);
            expr->callForAllChildren(function);
        }
    }
}