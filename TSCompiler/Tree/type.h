#pragma once
#include "../Semantic/JvmClass.h"
#include "node.h"

struct TypeNode final : Node
{
    enum class Type
    {
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
    JvmDataType *jvmParamType{};

    TypeNode(Type type) : type{type} {}
    TypeNode(const std::string name)
        : type{Type::_USER_TYPE}, userTypeName{name}
    {
    }

    void addJvmDataType(JvmDataType *type) { this->jvmParamType = type; }

    std::string toString() const noexcept override
    {
        std::string name = "TypeNode:\n";
        switch (type)
        {
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
            name += "UserType:\n" + std::string{userTypeName};
            break;
        default:
            break;
        }

        for (int i = 0; i < arrayArity; ++i)
        {
            name += "[]";
        }
        name += "\nJvmType: " + this->jvmParamType->toString();
        return name;
    }
};

inline JvmDataType *ToJvmDataType(const TypeNode *node)
{
    if (node->jvmParamType)
    {
        return node->jvmParamType;
    }
    JvmDataType *type;
    switch (node->type)
    {
    case TypeNode::Type::_NUMBER:
        type = new JvmDataType("JavaRTL/Number");
        break;
    case TypeNode::Type::_BOOLEAN:
        type = new JvmDataType("JavaRTL/Boolean");
        break;
    case TypeNode::Type::_STRING:
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
    }
    type->arrayArity = node->arrayArity;
    return type;
}
