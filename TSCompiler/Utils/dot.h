#pragma once
#include <ostream>
#include "../Tree/nodes.h"

void RunDot(std::string dotPath, std::string dotFilePath);

void ToDot(TSScriptNode* node, std::ostream& out);

void ToDot(TSElementListNode* node, std::ostream& out);
void ToDot(TSElementNode* node, std::ostream& out);

void ToDot(StatementListNode* node, std::ostream& out);
void ToDot(StatementNode* node, std::ostream& out);

void ToDot(ExpressionListNode* node, std::ostream& out);
void ToDot(ExpressionNode* node, std::ostream& out);

void ToDot(TupleTypeNode* node, std::ostream& out);
void ToDot(TypeNode* node, std::ostream& out);

void ToDot(VarDeclarationListNode* node, std::ostream& out);
void ToDot(VarDeclarationNode* node, std::ostream& out);
void ToDot(VarStatementNode* node, std::ostream& out);