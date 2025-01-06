#include "class.h"

VarDeclarationNode* ClassElementNode::findVariableByName(std::string name,
                                                         int scopingLevel)
{
    for (auto* variable : variables)
    {
        if (variable->identifierStr == name &&
            variable->scopingLevel <= scopingLevel)
            return variable;
    }
    if (isMainMethod)
    {
        auto prop = elemClass->body->findPropertyByName(name);
        if (prop)
            return prop->baseNode;
    }
    return nullptr;
}
