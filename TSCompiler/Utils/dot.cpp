#include <iostream>
#include <process.h>
#include <string>

#include "dot.h"


void RunDot(const std::string dotPath, const std::string dotFilePath)
{
    _spawnl(_P_NOWAIT, dotPath.data(), "dot", "-O", "-Tpng", dotFilePath.data(), nullptr);
}

std::string MakeNode(const std::size_t id, const std::string name, const std::string style = "")
{
    auto res = std::to_string(id) + " [label=\"" + name + "\"]";
    if (!style.empty()) { res += "[style = \"" + style + "\"]"; }
    res += "\n";
    return res;
}

std::string MakeConnection(const size_t id1, const size_t id2, std::string note = "")
{
    auto res = std::to_string(id1) + " -> " + std::to_string(id2);

    if (!note.empty())
        res += " [label=\"" + note + "\"]";

    res += "\n";
    return res;
}

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

//std::string QualifiedNameToString(IdentifierList* identifiers)
//{
//    if (!identifiers)
//        return "";
//    std::string name;
//    for (const auto& id : identifiers->Identifiers)
//    {
//        name += id;
//        name += '.';
//    }
//    name.pop_back();
//    return name;
//}
//void ToDot()

void ToDot(TupleTypeNode* node, std::ostream& out) {
    out << MakeNode(node->id, "TupleTypeNode");
    TypeNode* child = node->first;
    while (child != NULL) {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
        child = child->next;
    }
}

void ToDot(TypeNode* node, std::ostream& out) {
    out << MakeNode(node->id, "TypeNode");
    switch (node->type)
    {
    case TypeType::_NUMBER:
        out << MakeNode(node->id, "number");
        break;
    case TypeType::_STRING:
        out << MakeNode(node->id, "string");
        break;
    case TypeType::_BOOLEAN:
        out << MakeNode(node->id, "boolean");
        break;
    case TypeType::_UNDEFINED:
        out << MakeNode(node->id, "undefined");
        break;
    case TypeType::_VOID:
        out << MakeNode(node->id, "void");
        break;
    case TypeType::_NULL:
        out << MakeNode(node->id, "null");
        break;
    case TypeType::_ARRAY:
        out << MakeNode(node->id, "ArrayType");
        ToDot(node->arrayType, out);
        out << MakeConnection(node->id, node->arrayType->id, "Of");
        break;
    case TypeType::_TUPLE:
        ToDot(node->tupleNode, out);
        out << MakeConnection(node->id, node->tupleNode->id);
        break;
    default:
        break;
    }
}

void ToDot(VarDeclarationNode* node, std::ostream& out) {
    std::string name = "VarDeclarationNode\nName: " + std::string{ node->identifierStr };
    out << MakeNode(node->id, name);

    if (node->varType != nullptr) {
        ToDot(node->varType, out);
        out << MakeConnection(node->id, node->varType->id, "Var type");
    }

    if (node->initExpression != nullptr) {
        ToDot(node->initExpression, out);
        out << MakeConnection(node->id, node->initExpression->id, "Init");
    }
}


void ToDot(VarDeclarationListNode* node, std::ostream& out) {
    out << MakeNode(node->id, "VarDeclarationListNode");

    VarDeclarationNode* child = node->first;
    while (child != NULL) {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
        child = child->next;
    }
}

void ToDot(VarStatementNode* node, std::ostream& out) {
    std::string name = "VarStatementNode\\nModifierType: " + ToString(node->modifierType);
    out << MakeNode(node->id, name);

    ToDot(node->declList, out);
    out << MakeConnection(node->id, node->declList->id);
}

void ToDot(ExpressionListNode* node, std::ostream& out) {
    out << MakeNode(node->id, "ExpressionListNode");

    ExpressionNode* child = node->first;
    while (child != NULL) {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
        child = child->next;
    }
}

void ToDot(ExpressionNode* node, std::ostream& out) {
    switch (node->type)
    {
    case ExpressionType::_IDENTIFIER:
        out << MakeNode(node->id, "IdentName:\n" + std::string{ node->identifierString });
        break;
    case ExpressionType::_INT_LIT:
        out << MakeNode(node->id, "IntLiteral:\n" + std::to_string(node->intValue));
        break;
    case ExpressionType::_FLOAT_LIT:
        out << MakeNode(node->id, "FloatLiteral:\n" + std::to_string(node->floatValue));
        break;
    case ExpressionType::_STRING_LIT:
        out << MakeNode(node->id, "StringLiteral:\n\\\"" + std::string{ node->stringValue } + "\\\"");
        break;
    case ExpressionType::_COMMA:
        out << MakeNode(node->id, "CommaOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);

        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_FUNC_CALL:
        out << MakeNode(node->id, "FuncCall: " + std::string{node->identifierString} );

        ToDot(node->params, out);
        out << MakeConnection(node->id, node->params->id);
        break;
    case ExpressionType::_BRACKETS:
        out << MakeNode(node->id, "Brackets");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionType::_ARRAY_CREATION:
        out << MakeNode(node->id, "ArrayCreation");
        ToDot(node->params, out);
        out << MakeConnection(node->id, node->params->id);
        break;
    case ExpressionType::_ARRAY_EMPTY_ELEMENT:
        out << MakeNode(node->id, "ArrayEmptyElement");
        break;
    default:
        break;
    }
}

void ToDot(StatementNode* node, std::ostream& out) {
    out << MakeNode(node->id, "StatementNode");
    switch (node->type)
    {
    case StatementType::_EXPRESSION:
        ToDot(node->expression, out);
        out << MakeConnection(node->id, node->expression->id, "exprStmt");
        break;
    case StatementType::_VAR:
        ToDot(node->varStmt, out);
        out << MakeConnection(node->id, node->varStmt->id);
        break;
    default:
        break;
    }
}

void ToDot(StatementListNode* node, std::ostream& out) {
    out << MakeNode(node->id, "StatementListNode");

    StatementNode* child = node->first;
    while (child != NULL) {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
        child = child->next;
    }
}

void ToDot(TSElementNode* node, std::ostream& out) {
    out << MakeNode(node->id, "TSElementNode");
    ToDot(node->stmt, out);
    out << MakeConnection(node->id, node->stmt->id);

}

void ToDot(TSElementListNode* node, std::ostream& out) {
    out << MakeNode(node->id, "TSElementListNode");
    
    TSElementNode* child = node->first;
    while (child != NULL) {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
        child = child->next;
    }
}

void ToDot(TSScriptNode* node, std::ostream& out) {
    out << "digraph TSScript {\n";
    out << MakeNode(node->id, "Script");
    ToDot(node->elemList, out);
    out << MakeConnection(node->id, node->elemList->id);
    out << "}" << std::endl;
}