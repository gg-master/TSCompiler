#pragma once
#include "node.h"

struct TypeNode final : Node
{
    std::string_view name() const noexcept override { return "TypeNode"; }

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

    TypeNode(const std::string_view name) : userTypeName{name} {}
};