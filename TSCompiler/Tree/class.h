#pragma once
#include "node.h"

struct ClassElementNode : Node
{
    std::string_view name() const noexcept override { return "ClassElementNode"; }

    enum class Type
    {
        _CONSTRUCTOR,
        _PROPERTY,
        _METHOD
    } type {};

    std::string_view name;
    TypeNode *propertyAndReturnType;

    ExpressionNode *expression;

    RequiredParameterListNode *params;
    StatementListNode *methodBody;

    ClassElementNode(Type type, const std::string_view name)
};

struct ClassElementListNode final : NodeList<ClassElementListNode, ClassElementNode>
{
    using NodeList<ClassElementListNode, ClassElementNode>::NodeList;

    std::string_view name() const noexcept override { return "ClassElementListNode"; }
};

struct ClassDeclarationNode final : Node
{
    std::string_view name() const noexcept override { return "ClassDeclarationNode"; }

    std::string_view className;
    std::string_view heritageName;

    ClassElementListNode *body;

    ClassDeclarationNode(const std::string_view className, ClassElementListNode *const body)
        : className{className}, heritageName{}, body{body}
    {
    }

    ClassDeclarationNode(const std::string_view className, const std::string_view heritageName,
                         ClassElementListNode *const body)
        : className{className}, heritageName{heritageName}, body{body}
    {
    }
};
