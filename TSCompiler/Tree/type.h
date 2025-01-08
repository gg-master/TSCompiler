#pragma once
#include "../Semantic/jvm_class.h"
#include "node.h"

struct TypeNode final : Node
{
    enum class Type
    {
        _ANY,
        _NUMBER,
        _STRING,
        _BOOLEAN,
        _UNDEFINED,
        _VOID,
        _NULL,
        _USER_TYPE,
    } type{};

    int arrayArity{0};

    std::string userTypeName;

    // semantic setp
    JvmDataType *jvmType{};

    TypeNode(Type type) : type{type} {}
    TypeNode(const std::string name)
        : type{Type::_USER_TYPE}, userTypeName{name}
    {
    }

    TypeNode(JvmDataType *type) : jvmType{type} {}

    bool operator==(const TypeNode &other) const
    {
        if (jvmType)
            return *jvmType == *other.jvmType;

        if (type == Type::_ANY)
            return arrayArity == other.arrayArity;

        return type == other.type && arrayArity == other.arrayArity &&
               userTypeName == other.userTypeName;
    }

    bool operator!=(const TypeNode &other) const { return !(*this == other); }

    std::string toString() const noexcept override
    {
        if (jvmType)
            return jvmType->toString();

        std::string name{};
        switch (this->type)
        {
        case TypeNode::Type::_ANY:
            name += "any";
            break;
        case TypeNode::Type::_NUMBER:
            name += "number";
            break;
        case TypeNode::Type::_STRING:
            name += "string";
            break;
        case TypeNode::Type::_BOOLEAN:
            name += "boolean";
            break;
        case TypeNode::Type::_UNDEFINED:
            name += "undefined";
            break;
        case TypeNode::Type::_VOID:
            name += "void";
            break;
        case TypeNode::Type::_NULL:
            name += "null";
            break;
        case TypeNode::Type::_USER_TYPE:
            name += "UserType:\n" + this->userTypeName;
            break;
        default:
            break;
        }

        for (int i = 0; i < this->arrayArity; ++i) name += "[]";

        return name;
    }
};

inline JvmDataType *toJvmDataType(const TypeNode *node)
{
    if (!node)
        return new JvmDataType(RTL_ANY_TYPE);

    if (node->jvmType)
    {
        return node->jvmType;
    }
    JvmDataType *type;
    switch (node->type)
    {
    case TypeNode::Type::_NUMBER:
        // FIXME int and float are same number type
        type = new JvmDataType(JvmDataType::Type::Int);
        // type = new JvmDataType("JavaRTL/Number");
        break;
    case TypeNode::Type::_BOOLEAN:
        type = new JvmDataType(JvmDataType::Type::Bool);
        // type = new JvmDataType("JavaRTL/Boolean");
        break;
    case TypeNode::Type::_STRING:
        // type = new JvmDataType(JvmDataType::Type::String);
        type = new JvmDataType("JavaRTL/String");
        break;
    case TypeNode::Type::_UNDEFINED:
        type = new JvmDataType("JavaRTL/Undefined");
        break;
    case TypeNode::Type::_NULL:
        type = new JvmDataType("JavaRTL/Null");
        break;
    case TypeNode::Type::_VOID:
        type = new JvmDataType(JvmDataType::Type::Void);
        break;
    case TypeNode::Type::_USER_TYPE:
        type = new JvmDataType(node->userTypeName);
        break;
    default:
        type = new JvmDataType(RTL_ANY_TYPE);
        break;
    }
    type->arrayArity = node->arrayArity;
    return type;
}

inline bool isUnknown(TypeNode *node)
{
    if (!node)
        return true;

    if (!node->jvmType && (node->type == TypeNode::Type::_ANY ||
                           node->type == TypeNode::Type::_UNDEFINED ||
                           node->type == TypeNode::Type::_VOID))
    {
        return true;
    }

    if (*node->jvmType == RTL_ANY_TYPE || *node->jvmType == RTL_UNDEFINED_TYPE)
    {
        return true;
    }

    return false;
}
