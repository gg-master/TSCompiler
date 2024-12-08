#include "dot.h"

#include <process.h>
#include <string>

//using namespace std::string_literals;

void RunDot(const std::string_view dotPath, const std::string_view dotFilePath)
{
    _spawnl(_P_NOWAIT, dotPath.data(), "dot", "-O", "-Tsvg", dotFilePath.data(), nullptr);
}

std::string MakeNode(const std::size_t id, const std::string_view name, const std::string_view style = "")
{
    auto res = std::to_string(id) + " [label=\"" + std::string{ name } + "\"]";
    if (!style.empty()) { res += "[style = \"" + std::string{ style } + "\"]"; }
    res += "\n";
    return res;
}

std::string MakeConnection(const size_t id1, const size_t id2, std::string_view note = "")
{
    auto res = std::to_string(id1) + " -> " + std::to_string(id2);

    if (!note.empty())
        res += " [label=\"" + std::string{ note } + "\"]";

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

void ToDot(ExpressionNode* node, std::ostream& out) {
    switch (node->type)
    {
    case ExpressionType::_IDENTIFIER:
        out << MakeNode(node->id, std::string{ node->identifierString });
    default:
        break;
    }
}

void ToDot(StatementNode* node, std::ostream& out) {
    switch (node->type)
    {
    case StatementType::_EXPRESSION:
        out << MakeNode(node->id, "ExprStmt");
        ToDot(node->expression, out);
        out << MakeConnection(node->id, node->expression->id);
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