#pragma once
#include "../Semantic/JvmClass.h"
#include "expr.h"
#include "func.h"
#include "node.h"
#include "stmt.h"
#include "type.h"
#include <algorithm>
#include <iterator>

struct MethodArgumentDTO
{
    JvmDataType *type;
    std::string name;
};

inline MethodArgumentDTO ToMethodArgumentDTO(RequiredParameterNode *node)
{
    return {ToJvmDataType(node->paramType), std::string{node->paramName}};
}

struct ClassDeclarationNode;

struct ClassElementNode final : Node
{
public:
    enum class Type
    {
        _CONSTRUCTOR,
        _PROPERTY,
        _METHOD
    } type{};

    std::string name{};
    TypeNode *propertyAndReturnType{};

    ExpressionNode *expression{};

    RequiredParameterListNode *params{};
    StatementListNode *methodBody{};

    // semantic step
    JvmDataType *jvmPropertyAndReturnType{};
    std::vector<MethodArgumentDTO> argumentsDTO{};

    ClassDeclarationNode *elemClass{};

    ClassElementNode(RequiredParameterListNode *params, StatementListNode *body)
        : type{Type::_CONSTRUCTOR}, params{params}, methodBody{body}
    {
    }

    ClassElementNode(const std::string name, TypeNode *propertyType,
                     ExpressionNode *expression)
        : type{Type::_PROPERTY}, name{name},
          propertyAndReturnType{propertyType}, expression{expression}
    {
    }

    ClassElementNode(const std::string name, RequiredParameterListNode *params,
                     TypeNode *returnType, StatementListNode *body)
        : type{Type::_METHOD}, name{name}, params{params},
          propertyAndReturnType{returnType}, methodBody{body}
    {
    }

    ClassElementNode(const FunctionDeclarationNode *node)
        : type{Type::_METHOD}, name{node->funcName}, params{node->params},
          propertyAndReturnType{node->returnType}, methodBody{node->body}
    {
    }

    std::string toString() const noexcept override
    {
        return "ClassElementNode";
    }

    void analyzeArguments()
    {
        auto &&varDeclNodes = params->GetSeq();
        std::transform(varDeclNodes.begin(), varDeclNodes.end(),
                       std::back_inserter(argumentsDTO), ToMethodArgumentDTO);
    }
};

struct ClassElementListNode final
    : NodeList<ClassElementListNode, ClassElementNode>
{
    using NodeList<ClassElementListNode, ClassElementNode>::NodeList;

    std::string toString() const noexcept override
    {
        return "ClassElementListNode";
    }
};

struct ClassDeclarationNode final : Node
{
    std::string className{};
    std::string heritageName{};

    ClassElementListNode *body;

    ClassDeclarationNode(const std::string className,
                         ClassElementListNode *const body)
        : className{className}, body{body}
    {
    }

    ClassDeclarationNode(const std::string className,
                         const std::string heritageName,
                         ClassElementListNode *const body)
        : className{className}, heritageName{heritageName}, body{body}
    {
    }
    std::string toString() const noexcept override
    {
        return "ClassDeclarationNode";
    }
};
