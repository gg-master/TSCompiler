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

    ExpressionNode *initInConstructor{};

    ClassDeclarationNode *elemClass{};

    bool isPropertyAssigned = false;
    VarDeclarationNode *baseNode{};  // using for variables in main class

    std::vector<VarDeclarationNode *> variables{};

    bool isMainMethod = false;
    bool isStatic = false;

    ClassElementNode(RequiredParameterListNode *params, StatementListNode *body)
        : type{Type::_CONSTRUCTOR},
          name{"<init>"},
          params{params},
          methodBody{body}
    {
    }

    ClassElementNode(const std::string name, TypeNode *propertyType,
                     ExpressionNode *expression, bool isStatic = false)
        : type{Type::_PROPERTY},
          name{name},
          propertyAndReturnType{propertyType},
          expression{expression},
          isStatic{isStatic}
    {
        if (expression) isPropertyAssigned = true;
    }

    ClassElementNode(const std::string name, RequiredParameterListNode *params,
                     TypeNode *returnType, StatementListNode *body,
                     bool isStatic = false)
        : type{Type::_METHOD},
          name{name},
          params{params},
          propertyAndReturnType{returnType},
          methodBody{body},
          isStatic{isStatic}
    {
    }

    ClassElementNode(const FunctionDeclarationNode *node)
        : type{Type::_METHOD},
          name{node->funcName},
          params{node->params},
          propertyAndReturnType{node->returnType},
          methodBody{node->body},
          isStatic{true}
    {
    }

    bool isConstructor() const
    {
        return type == ClassElementNode::Type::_CONSTRUCTOR;
    }

    std::string toString() const noexcept override
    {
        return "ClassElementNode";
    }

    std::string toDescriptor() const
    {
        if (type == ClassElementNode::Type::_PROPERTY)
            return propertyAndReturnType->jvmType->toDescriptor();

        std::string desc = "(";
        for (const auto &param : params->GetSeq())
        {
            desc += param->paramType->jvmType->toDescriptor();
        }
        desc += ")";

        desc += propertyAndReturnType->jvmType->toDescriptor();

        /*if (type != ClassElementNode::Type::_CONSTRUCTOR)
            desc = "V";*/

        return desc;
    }

    void analyzeArguments()
    {
        for (auto *param : params->GetSeq())
        {
            param->paramType = new TypeNode(toJvmDataType(param->paramType));
        }
    }

    VarDeclarationNode *findVariableByName(std::string name, int scopingLevel);
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

    ClassElementNode *findMethodByName(std::string name) const
    {
        for (auto *method : GetMethods())
        {
            if (method->name == name)
            {
                return method;
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

    // if in constructor last stmt is return. then new class exported via that
    ClassDeclarationNode *returnedClassFromConstructor;

    ClassElementNode *thisProp;
    ClassElementNode *superProp;

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
