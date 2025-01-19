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

    bool isComputed = false;

    // semantic setp
    JvmDataType *jvmType{};

    TypeNode(Type type, bool isComputed = false)
        : type{type}, isComputed{isComputed}
    {
    }
    TypeNode(const std::string name)
        : type{Type::_USER_TYPE}, userTypeName{name}
    {
    }

    TypeNode(JvmDataType *type, bool isComputed = false)
        : jvmType{type},
          arrayArity{type->arrayArity},
          isComputed{isComputed || type->isComputed}
    {
    }

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

        if (isComputed)
            name += "\nCOMP";

        return name;
    }
};

inline JvmDataType *toJvmDataType(const TypeNode *node)
{
    JvmDataType *type;

    if (!node)
    {
        type = new JvmDataType(RTL_ANY_TYPE);
        type->isComputed = true;
        return type;
    }

    if (node->jvmType)
    {
        return node->jvmType;
    }

    switch (node->type)
    {
    case TypeNode::Type::_NUMBER:
        type = new JvmDataType(RTL_NUMBER_TYPE);
        break;
    case TypeNode::Type::_BOOLEAN:
        type = new JvmDataType(RTL_BOOLEAN_TYPE);
        break;
    case TypeNode::Type::_STRING:
        type = new JvmDataType(RTL_STRING_TYPE);
        break;
    case TypeNode::Type::_UNDEFINED:
        type = new JvmDataType(RTL_UNDEFINED_TYPE);
        break;
    case TypeNode::Type::_NULL:
        type = new JvmDataType(RTL_NULL_TYPE);
        break;
    case TypeNode::Type::_VOID:
        type = new JvmDataType(RTL_VOID_TYPE);
        break;
    case TypeNode::Type::_USER_TYPE:
        type = new JvmDataType(node->userTypeName);
        break;
    default:
        type = new JvmDataType(RTL_ANY_TYPE);
        type->isComputed = true;
        break;
    }

    type->isComputed = type->isComputed || node->isComputed;

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

    if (node->jvmType && (*node->jvmType == RTL_ANY_TYPE ||
                          *node->jvmType == RTL_UNDEFINED_TYPE ||
                          *node->jvmType == RTL_VOID_TYPE ||
                          node->jvmType->type == JvmDataType::Type::Void))
    {
        return true;
    }

    return false;
}
