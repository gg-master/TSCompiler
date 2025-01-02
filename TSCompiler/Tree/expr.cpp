#include "expr.h"

#include "../Semantic/jvm_class.h"

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

ExpressionNode *ExpressionNode::toASsignOnArrayElement() const
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

void ExpressionNode::applyToAllChildren(
    const std::function<ExpressionNode *(ExpressionNode *)> &mapFunction)
{
    if (firstOperand)
        firstOperand = mapFunction(firstOperand);
    if (secondOperand)
        secondOperand = mapFunction(secondOperand);
    if (thirdOperand)
        thirdOperand = mapFunction(thirdOperand);

    if (params)
        for (auto &expr : params->GetSeq()) expr = mapFunction(expr);
}

void ExpressionNode::callForAllChildren(
    const std::function<void(ExpressionNode *)> &function) const
{
    if (firstOperand)
        function(firstOperand);
    if (secondOperand)
        function(secondOperand);
    if (thirdOperand)
        function(thirdOperand);

    if (params)
        for (auto &expr : params->GetSeq()) function(expr);
}
