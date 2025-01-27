#include "class.h"

VarDeclarationNode* ClassElementNode::findVariableByName(std::string name,
                                                         int scopingLevel,
                                                         int minScopingLevel)
{
    for (auto it = variables.rbegin(); it != variables.rend(); ++it)
    {
        auto variable = *it;
        if (variable->identifierStr == name &&
            variable->scopingLevel <= scopingLevel &&
            variable->scopingLevel >= minScopingLevel)
            return variable;
    }
    return nullptr;
}
