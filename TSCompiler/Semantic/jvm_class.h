#pragma once
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

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

    std::vector<std::string> complex{};

    JvmDataType() : type{Type::Complex}, complex{"JavaRTL", "Any"} {}
    JvmDataType(Type type) : type{type} {}
    JvmDataType(const std::string &complexStr) : type{Type::Complex}, complex{}
    {
        std::stringstream ss(complexStr);
        std::string segment;
        while (std::getline(ss, segment, '/'))
        {
            if (!segment.empty())
            {
                complex.push_back(segment);
            }
        }
    }

    bool operator==(const JvmDataType &other) const
    {
        return (type == other.type ||
                (type == Type::Complex &&
                 complex == std::vector<std::string>{"JavaRTL", "Any"})) &&
               arrayArity == other.arrayArity;
    }

    bool operator!=(const JvmDataType &other) const
    {
        return !(*this == other);
    }

    bool isReferenceType() const
    {
        return type == Type::Complex || arrayArity >= 1 || type == Type::String;
    }

    bool isPrimitiveType() const
    {
        return (type == Type::Int || type == Type::Float ||
                type == Type::Bool) &&
               arrayArity == 0;
    }

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
            for (auto part : complex) name += part + '/';
            name.pop_back();
            break;
        case JvmDataType::Type::Void:
            name += "void";
            break;
        }
        for (int i = 0; i < this->arrayArity; ++i) name += "[]";
        return name;
    }

    std::string toDescriptor() const
    {
        if (arrayArity > 0)
        {
            auto subtype = *this;
            subtype.arrayArity -= 1;
            return "[" + subtype.toDescriptor();
        }
        switch (type)
        {
        case Type::Int:
            return "I";
        case Type::Bool:
            return "Z";
        case Type::Float:
            return "F";
        case Type::String:
            return "Ljava/lang/String;";
        case Type::Complex:
        {
            std::string value = "L";
            for (auto part : complex) value += part + '/';
            value.back() = ';';
            return value;
        }
        case Type::Void:
            return "V";
        }
        return {};
    }

    std::string toTypename() const
    {
        if (type != Type::Complex)
            return toDescriptor();

        std::string name{};
        for (auto part : complex) name += part + '/';
        name.pop_back();
        return name;
    }
};

inline std::string toString(std::vector<JvmDataType> const &container)
{
    std::string str = "<";
    for (auto it = container.begin(); it != container.end(); ++it)
    {
        std::string suffix = ", ";
        if (it == std::prev(container.end()))
            suffix = "";

        str += ((JvmDataType)*it).toString();
        str += suffix;
    }
    str += '>';
    return str;
}

const inline JvmDataType JAVA_OBJECT_TYPE = []
{
    JvmDataType type{"java/lang/Object"};
    return type;
}();

const inline JvmDataType RTL_ANY_TYPE = []
{
    JvmDataType type{"JavaRTL/Any"};
    return type;
}();

const inline JvmDataType RTL_STRING_TYPE = []
{
    JvmDataType type{"JavaRTL/String"};
    return type;
}();

const inline JvmDataType RTL_NUMBER_TYPE = []
{
    JvmDataType type{"JavaRTL/Number"};
    return type;
}();

const inline JvmDataType RTL_BOOLEAN_TYPE = []
{
    JvmDataType type{"JavaRTL/Boolean"};
    return type;
}();

const inline JvmDataType RTL_UNDEFINED_TYPE = []
{
    JvmDataType type{"JavaRTL/Undefined"};
    return type;
}();

const inline JvmDataType RTL_NULL_TYPE = []
{
    JvmDataType type{"JavaRTL/Null"};
    return type;
}();
