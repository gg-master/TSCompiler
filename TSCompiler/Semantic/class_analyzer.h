#pragma once
#include <string>
#include <vector>

#include "../Tree/ts_script.h"

struct ClassAnalyzer
{
    TSScriptNode *root;

    ClassElementNode *currentField = nullptr;
    ClassElementNode *currentMethod = nullptr;
    ClassDeclarationNode *currentClass = nullptr;

    std::vector<std::string> errors{};

    int currentScopingLevel = 0;

    void incrementScopingLevel() { currentScopingLevel++; }

    void decrementScopingLevel()
    {
        if (currentMethod && currentScopingLevel > 0)
        {
            for (auto *varDecl : currentMethod->variables)
            {
                if (varDecl->scopingLevel == currentScopingLevel)
                    varDecl->identifierStr = "";
            }
            currentScopingLevel--;
        }
    }

    explicit ClassAnalyzer(TSScriptNode *root) : root{root} {}

    void attributeClass(ClassDeclarationNode *node);

    void resolveClassConstructor();

    void attributeMemberSignatures();
    void attributeClassProperty(ClassElementNode *node);

    void analyzeClass(ClassDeclarationNode *node);

    void analyzeClassConstructor();
    void analyzeClassFields();
    void analyzeClassMethod(ClassElementNode *node);

    void analyzeStmt(StatementNode *node, StatementListNode *newSeq = nullptr);

    StatementNode *analyzeVarDeclaration(VarDeclarationNode *node = nullptr);

    ExpressionNode *analyzeExpr(ExpressionNode *node);

    void analyzeSuperCall(ExpressionNode *node);
    void analyzeFuncCall(ExpressionNode *node);
    void analyzeMethodCall(ExpressionNode *node);
    void analyzeNewCall(ExpressionNode *node);

    void analyzeRequiredParam(RequiredParameterNode *param);

    TypeNode *calculateTypeForExpr(ExpressionNode *node);

    static ExpressionNode *replaceAssignmentsOnArrayElements(
        ExpressionNode *node);
    static ExpressionNode *replaceAssignmentsOnField(ExpressionNode *node);

    void validateTypename(JvmDataType *jvmDataType);
    ClassDeclarationNode *findClass(JvmDataType *jvmDataType) const;

    void moveFunctionScopedVarsOnTop();
};
