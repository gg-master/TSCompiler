#pragma once
#include "../Tree/ts_script.h"
#include <set>
#include <string>
#include <vector>

struct Semantic
{
    TSScriptNode *root;

    std::set<std::string> errors;

    Semantic(TSScriptNode *root) : root{root} {}

    void analyze(std::string nameMainClass)
    {
        bool isOk = checkBuiltInClasses(nameMainClass);
        if (!isOk)
            return;
    }

    bool checkBuiltInClasses(std::string nameMainClass)
    {
        for (const auto *userClass : root->classes)
        {
            std::string clsName = userClass->className;
            if (clsName == "Number")
            {
                errors.insert("Duplicate identifier 'Number'");
            }
            else if (clsName == "String")
            {
                errors.insert("Duplicate identifier 'String'");
            }
            else if (clsName == "Boolean")
            {
                errors.insert("Duplicate identifier 'Boolean'");
            }
            else if (clsName == nameMainClass)
            {
                errors.insert("Duplicate identifier '" + nameMainClass + "'");
            }
        }
        if (!errors.empty())
            return false;

        root->add(createNumberClass());
        root->add(createBooleanClass());
        root->add(createStringClass());
        root->add(createNullClass());
        root->add(createUndefinedClass());
        root->add(createConsoleClass());

        root->add(createMainClass(nameMainClass));
        return true;
    }

    static ClassDeclarationNode *createNumberClass();
    static ClassDeclarationNode *createBooleanClass();
    static ClassDeclarationNode *createStringClass();
    static ClassDeclarationNode *createNullClass();
    static ClassDeclarationNode *createUndefinedClass();
    static ClassDeclarationNode *createConsoleClass();

    ClassDeclarationNode *createMainClass(std::string name)
    {
        std::string mainMethodName = name + "_main";

        auto *body = ClassElementListNode::makeEmpty();

        for (const auto *function : root->functions)
        {
            if (function->funcName == mainMethodName)
            {
                errors.insert("Duplicate identifier '" + mainMethodName + "'");
                continue;
            }
            body->add(new ClassElementNode(function));
        }

        auto *mainBody = StatementListNode::makeEmpty();
        for (auto *stmt : root->statements)
        {
            mainBody->add(stmt);
        }

        auto *mainMethod = new ClassElementNode(
            mainMethodName, RequiredParameterListNode::makeEmpty(), nullptr,
            mainBody);
        mainMethod->jvmPropertyAndReturnType =
            new JvmDataType(JvmDataType::Type::Void);

        body->add(mainMethod);

        auto *mainCls = new ClassDeclarationNode(name, body);

        root->functions.clear();
        root->statements.clear();

        return mainCls;
    }
};
