#pragma once
#include "../Tree/ts_script.h"
#include <ostream>

void RunDot(std::string dotPath, std::string dotFilePath);

void ToDot(TSScriptNode *node, std::ostream &out);

void ToDot(TSElementListNode *node, std::ostream &out);
void ToDot(TSElementNode *node, std::ostream &out);

void ToDot(ClassDeclarationNode *node, std::ostream &out);
void ToDot(ClassElementListNode *node, std::ostream &out);
void ToDot(ClassElementNode *node, std::ostream &out);

void ToDot(FunctionDeclarationNode *node, std::ostream &out);
void ToDot(RequiredParameterListNode *node, std::ostream &out);
void ToDot(RequiredParameterNode *node, std::ostream &out);

void ToDot(StatementListNode *node, std::ostream &out);
void ToDot(StatementNode *node, std::ostream &out);

void ToDot(ExpressionListNode *node, std::ostream &out);
void ToDot(ExpressionNode *node, std::ostream &out);

void ToDot(TypeNode *node, std::ostream &out);

void ToDot(VarDeclarationListNode *node, std::ostream &out);
void ToDot(VarDeclarationNode *node, std::ostream &out);