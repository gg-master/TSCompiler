#pragma once
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

    std::string complex{};

    JvmDataType() : type{Type::Complex}, complex{"JavaRTL/Any"} {}
    JvmDataType(Type type) : type{type} {}
    JvmDataType(const std::string complex)
        : type{Type::Complex}, complex{complex}
    {
    }

    bool operator==(const JvmDataType &other) const
    {
        return type == other.type && arrayArity == other.arrayArity;
    }

    bool operator!=(const JvmDataType &other) const
    {
        return !(*this == other);
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
            name += this->complex;
            break;
        case JvmDataType::Type::Void:
            name += "void";
            break;
        }
        for (int i = 0; i < this->arrayArity; ++i) name += "[]";
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

const inline JvmDataType RTL_ANY_TYPE = []
{
    JvmDataType type{"JavaRTL/Any"};
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

// const inline JvmDataType RTL_STRING_TYPE = []
// {
//     JvmDataType type{"JavaRTL/String"};
//     return type;
// }();