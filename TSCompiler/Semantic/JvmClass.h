#pragma once
#include <string>

struct JvmDataType
{
    enum class Type
    {
        Int,
        Float,
        Bool,
        String,
        Complex,
        Void
    } type{};

    int arrayArity = 0;

    std::string complex{};

    JvmDataType(Type type) : type{type} {}
    JvmDataType(const std::string complex) : type{Type::Complex}, complex{complex} {}

    bool operator==(const JvmDataType &other) const
    {
        return type == other.type && arrayArity == other.arrayArity;
    }

    bool operator!=(const JvmDataType &other) const { return !(*this == other); }

    std::string toString()
    {
        std::string name;
        switch (this->type)
        {
        case JvmDataType::Type::Int:
            name += "int";
            break;
        case JvmDataType::Type::Float:
            name += "float";
            break;
        case JvmDataType::Type::String:
            name += "string";
            break;
        case JvmDataType::Type::Complex:
            name += this->complex;
            break;
        case JvmDataType::Type::Void:
            name += "void";
            break;
        }
        for (int i = 0; i < this->arrayArity; ++i)
            name += "[]";
        return name;
    }
};
