#pragma once
#include "node.h"

struct TypeNode final : Node
{
    std::string_view Name() const noexcept override { return "TypeNode"; }

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

    std::string_view userTypeName;

    TypeNode(Type type) : type{type} {}
    TypeNode(const std::string_view name) : type{Type::_USER_TYPE}, userTypeName{name} {}
};