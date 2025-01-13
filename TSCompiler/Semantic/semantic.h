#pragma once
#include <set>
#include <string>
#include <vector>

#include "../Tree/ts_script.h"
#include "class_analyzer.h"

struct Semantic
{
    TSScriptNode *root;

    std::set<std::string> errors;

    Semantic(TSScriptNode *root) : root{root} {}

    void analyze(std::string mainClassName)
    {
        bool isOk = checkBuiltInClasses(mainClassName);
        if (!isOk)
            return;

        ClassAnalyzer analyzer(root);

        for (auto *class_ : root->classes)
        {
            analyzer.attributeClass(class_);
        }
        for (auto *class_ : root->classes)
        {
            analyzer.analyzeClass(class_);
        }

        errors.insert(analyzer.errors.begin(), analyzer.errors.end());
    }

    bool checkBuiltInClasses(std::string mainClassName)
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
            else if (clsName == mainClassName)
            {
                errors.insert("Duplicate identifier '" + mainClassName + "'");
            }
        }
        if (!errors.empty())
            return false;

        root->add(createAnyClass());
        root->add(createNumberClass());
        root->add(createBooleanClass());
        root->add(createStringClass());
        root->add(createNullClass());
        root->add(createUndefinedClass());
        root->add(createVoidClass());
        root->add(createConsoleClass());

        this->root->mainClass = createMainClass(mainClassName);
        root->add(this->root->mainClass);
        return true;
    }

    static ClassDeclarationNode *createAnyClass();
    static ClassDeclarationNode *createNumberClass();
    static ClassDeclarationNode *createBooleanClass();
    static ClassDeclarationNode *createStringClass();
    static ClassDeclarationNode *createNullClass();
    static ClassDeclarationNode *createUndefinedClass();
    static ClassDeclarationNode *createVoidClass();
    static ClassDeclarationNode *createConsoleClass();

    ClassDeclarationNode *createMainClass(std::string name)
    {
        std::string mainMethodName = "main";

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
            // adding global "var" stmt as main property
            for (auto *varStmt : stmt->getAllFunctionScopedVars())
            {
                auto *existProp =
                    body->findPropertyByName(varStmt->identifierStr);

                if (existProp)
                {
                    if (*existProp->propertyAndReturnType !=
                            *varStmt->varType &&
                        !varStmt->initExpression && !existProp->expression)
                    {
                        errors.insert(
                            "Subsequent variable declarations must have the "
                            "same type. Variable '" +
                            varStmt->identifierStr + "' must be of type '" +
                            existProp->propertyAndReturnType->toString() +
                            "', but here has type '" +
                            varStmt->varType->toString() + "'");
                    }
                    continue;
                }

                auto *prop = new ClassElementNode(
                    varStmt->identifierStr, varStmt->varType, nullptr, true);
                prop->baseNode = varStmt;
                body->add(prop);
            }

            // special case for "let" and "const" in global scope
            if (stmt->type == StatementNode::Type::_VAR && stmt->declList &&
                isBlockScopeVar(stmt->modifierType))
            {
                for (auto *varDecl : stmt->declList->GetSeq())
                {
                    if (body->findPropertyByName(varDecl->identifierStr))
                    {
                        // errors.insert("Duplicate identifier '" +
                        //               varDecl->identifierStr + "'");
                        continue;
                    }

                    auto *prop = new ClassElementNode(
                        varDecl->identifierStr, varDecl->varType, nullptr, true);
                    prop->baseNode = varDecl;
                    body->add(prop);
                }
            }
            mainBody->add(stmt);
        }

        auto *mainMethod = new ClassElementNode(
            mainMethodName, RequiredParameterListNode::makeEmpty(), nullptr,
            mainBody, true);
        mainMethod->propertyAndReturnType =
            new TypeNode(new JvmDataType(JvmDataType::Type::Void));
        mainMethod->isMainMethod = true;

        body->add(mainMethod);

        auto *mainCls = new ClassDeclarationNode(name, body);

        root->functions.clear();
        root->statements.clear();

        return mainCls;
    }

    void generate() const
    {
        if (!errors.empty())
            return;
        
        for (auto class_ : root->classes)
        {
            if (class_->className.starts_with("JavaRTL"))
                continue;

            ClassAnalyzer analyzer(root);
            analyzer.currentClass = class_;

            analyzer.fillTables();
            analyzer.generate();
        }
    }
};
