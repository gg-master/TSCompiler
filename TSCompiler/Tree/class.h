#pragma once
#include <algorithm>
#include <iterator>

#include "../Semantic/jvm_class.h"
#include "func.h"
#include "node.h"
#include "stmt.h"
#include "type.h"

struct ExpressionNode;
struct ClassDeclarationNode;

struct ClassElementNode final : Node
{
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

    // semantic step belows

    ClassDeclarationNode *elemClass{};
    VarDeclarationNode *baseNode{};  // using for variables in main class

    std::vector<VarDeclarationNode *> variables{};

    ClassElementNode(RequiredParameterListNode *params, StatementListNode *body)
        : type{Type::_CONSTRUCTOR}, params{params}, methodBody{body}
    {
    }

    ClassElementNode(const std::string name, TypeNode *propertyType,
                     ExpressionNode *expression)
        : type{Type::_PROPERTY},
          name{name},
          propertyAndReturnType{propertyType},
          expression{expression}
    {
    }

    ClassElementNode(const std::string name, RequiredParameterListNode *params,
                     TypeNode *returnType, StatementListNode *body)
        : type{Type::_METHOD},
          name{name},
          params{params},
          propertyAndReturnType{returnType},
          methodBody{body}
    {
    }

    ClassElementNode(const FunctionDeclarationNode *node)
        : type{Type::_METHOD},
          name{node->funcName},
          params{node->params},
          propertyAndReturnType{node->returnType},
          methodBody{node->body}
    {
    }

    std::string toString() const noexcept override
    {
        return "ClassElementNode";
    }

    void analyzeArguments()
    {
        for (auto *param : params->GetSeq())
        {
            param->paramType = new TypeNode(toJvmDataType(param->paramType));
        }
    }

    VarDeclarationNode *findVariableByName(std::string name, int scopingLevel)
    {
        for (auto *variable : variables)
        {
            if (variable->identifierStr == name &&
                variable->scopingLevel <= scopingLevel)
                return variable;
        }
        return nullptr;
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

    std::vector<ClassElementNode *> GetConstructors() const
    {
        std::vector<ClassElementNode *> nodes;
        for (ClassElementNode *node : GetSeq())
        {
            if (node->type == ClassElementNode::Type::_CONSTRUCTOR)
            {
                nodes.push_back(node);
            }
        }
        return nodes;
    }

    std::vector<ClassElementNode *> GetMethods() const
    {
        std::vector<ClassElementNode *> nodes;
        for (ClassElementNode *node : GetSeq())
        {
            if (node->type == ClassElementNode::Type::_METHOD)
            {
                nodes.push_back(node);
            }
        }
        return nodes;
    }

    std::vector<ClassElementNode *> GetProperties() const
    {
        std::vector<ClassElementNode *> nodes;
        for (ClassElementNode *node : GetSeq())
        {
            if (node->type == ClassElementNode::Type::_PROPERTY)
            {
                nodes.push_back(node);
            }
        }
        return nodes;
    }

    ClassElementNode *findPropertyByName(
        std::string name, ClassElementNode *beforeNode = nullptr) const
    {
        for (auto *property : GetProperties())
        {
            if (property->name == name)
            {
                return property;
            }
            if (property == beforeNode)
            {
                return nullptr;
            }
        }
        return nullptr;
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

    JvmDataType *toDataType() const { return new JvmDataType(this->className); }
};
