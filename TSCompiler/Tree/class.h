#pragma once
#include "expr.h"
#include "func.h"
#include "node.h"
#include "stmt.h"
#include "type.h"

struct ClassElementNode final : Node
{
public:
    enum class Type
    {
        _CONSTRUCTOR,
        _PROPERTY,
        _METHOD
    } type{};

    std::string_view name{};
    TypeNode *propertyAndReturnType{};

    ExpressionNode *expression{};

    RequiredParameterListNode *params{};
    StatementListNode *methodBody{};

    ClassElementNode(RequiredParameterListNode *params, StatementListNode *body)
        : type{Type::_CONSTRUCTOR}, params{params}, methodBody{body}
    {
    }

    ClassElementNode(const std::string_view name, TypeNode *propertyType,
                     ExpressionNode *expression)
        : type{Type::_PROPERTY}, name{name}, propertyAndReturnType{propertyType},
          expression{expression}
    {
    }

    ClassElementNode(const std::string_view name, RequiredParameterListNode *params,
                     TypeNode *returnType, StatementListNode *body)
        : type{Type::_METHOD}, name{name}, params{params}, propertyAndReturnType{returnType}, methodBody{body}
    {
    }

    std::string_view Name() const noexcept override { return "ClassElementNode"; }
};

struct ClassElementListNode final : NodeList<ClassElementListNode, ClassElementNode>
{
    using NodeList<ClassElementListNode, ClassElementNode>::NodeList;

    std::string_view Name() const noexcept override { return "ClassElementListNode"; }
};

struct ClassDeclarationNode final : Node
{
    std::string_view className{};
    std::string_view heritageName{};

    ClassElementListNode *body;

    ClassDeclarationNode(const std::string_view className, ClassElementListNode *const body)
        : className{className}, body{body}
    {
    }

    ClassDeclarationNode(const std::string_view className, const std::string_view heritageName,
                         ClassElementListNode *const body)
        : className{className}, heritageName{heritageName}, body{body}
    {
    }
    std::string_view Name() const noexcept override { return "ClassDeclarationNode"; }
};
