#include <iostream>
#include <process.h>
#include <string>

#include "dot.h"

void RunDot(const std::string dotPath, const std::string dotFilePath) {
    _spawnl(_P_NOWAIT, dotPath.data(), "dot", "-O", "-Tpng", dotFilePath.data(), NULL);
}

std::string MakeNode(const std::size_t id, const std::string name, const std::string style = "") {
    auto res = std::to_string(id) + " [label=\"" + name + "\"]";
    if (!style.empty()) {
        res += "[style = \"" + style + "\"]";
    }
    res += "\n";
    return res;
}

std::string MakeConnection(const size_t id1, const size_t id2, std::string note = "") {
    auto res = std::to_string(id1) + " -> " + std::to_string(id2);

    if (!note.empty())
        res += " [label=\"" + note + "\"]";

    res += "\n";
    return res;
}

void ToDot(TupleTypeNode *node, std::ostream &out) {
    out << MakeNode(node->id, "TupleTypeNode");
    TypeNode *child = node->first;
    while (child != NULL) {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
        child = child->next;
    }
}

void ToDot(TypeNode *node, std::ostream &out) {
    out << MakeNode(node->id, "TypeNode");
    switch (node->type) {
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
    case TypeType::_USER_TYPE:
        out << MakeNode(node->id, "UserType:\n" + std::string{node->userTypeName});
        break;
    default:
        break;
    }
}

void ToDot(VarDeclarationNode *node, std::ostream &out) {
    std::string name = "VarDeclarationNode\nName: " + std::string{node->identifierStr};
    out << MakeNode(node->id, name);

    if (node->varType != NULL) {
        ToDot(node->varType, out);
        out << MakeConnection(node->id, node->varType->id, "type");
    }

    if (node->initExpression != NULL) {
        ToDot(node->initExpression, out);
        out << MakeConnection(node->id, node->initExpression->id, "init");
    }
}

void ToDot(VarDeclarationListNode *node, std::ostream &out) {
    out << MakeNode(node->id, "VarDeclarationListNode");

    VarDeclarationNode *child = node->first;
    while (child != NULL) {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
        child = child->next;
    }
}

void ToDot(ExpressionListNode *node, std::ostream &out) {
    out << MakeNode(node->id, "ExpressionListNode");

    ExpressionNode *child = node->first;
    while (child != NULL) {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
        child = child->next;
    }
}

void ToDot(ExpressionNode *node, std::ostream &out) {
    std::string name;
    switch (node->type) {
    case ExpressionType::_IDENTIFIER:
        out << MakeNode(node->id, "IdentName:\n" + std::string{node->identifierString});
        break;
    case ExpressionType::_INT_LIT:
        out << MakeNode(node->id, "IntLiteral:\n" + std::to_string(node->intValue));
        break;
    case ExpressionType::_FLOAT_LIT:
        out << MakeNode(node->id, "FloatLiteral:\n" + std::to_string(node->floatValue));
        break;
    case ExpressionType::_STRING_LIT:
        out << MakeNode(node->id, "StringLiteral:\n\\\"" + std::string{node->stringValue} + "\\\"");
        break;
    case ExpressionType::_BOOLEAN_LIT:
        if (node->boolValue) {
            name = "true";
        } else {
            name = "false";
        }
        out << MakeNode(node->id, "BooleanLiteral:\n" + name);
        break;
    case ExpressionType::_NULL_LIT:
        out << MakeNode(node->id, "NullLiteral");
        break;
    case ExpressionType::_UNDEFINED_LIT:
        out << MakeNode(node->id, "UndefinedLiteral");
        break;
    case ExpressionType::_THIS:
        out << MakeNode(node->id, "This");
        break;

    case ExpressionType::_PREF_INCREMENT:
        out << MakeNode(node->id, "PrefIncrement");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionType::_PREF_DECREMENT:
        out << MakeNode(node->id, "PrefDecrement");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionType::_POST_INCREMENT:
        out << MakeNode(node->id, "PostIncrement");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionType::_POST_DECREMENT:
        out << MakeNode(node->id, "PostDecrement");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;

    case ExpressionType::_PLUS:
        out << MakeNode(node->id, "PlusOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_MINUS:
        out << MakeNode(node->id, "MinusOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_MUL:
        out << MakeNode(node->id, "MulOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_DIV:
        out << MakeNode(node->id, "DivOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_LESS:
        out << MakeNode(node->id, "LessOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_GREAT:
        out << MakeNode(node->id, "GreatOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;

    case ExpressionType::_UPLUS:
        out << MakeNode(node->id, "UnaryPlusOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionType::_UMINUS:
        out << MakeNode(node->id, "UnaryMinusOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;

    case ExpressionType::_NOT:
        out << MakeNode(node->id, "LogicalNot");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        break;
    case ExpressionType::_LOGICAL_OR:
        out << MakeNode(node->id, "LogicalOr");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_LOGICAL_AND:
        out << MakeNode(node->id, "LogicalAnd");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;

    case ExpressionType::_ASSIGN:
        out << MakeNode(node->id, "Assign");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_ASSIGN_MUL:
        out << MakeNode(node->id, "AssignMul");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_ASSIGN_DIV:
        out << MakeNode(node->id, "AssignDiv");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_ASSIGN_PLUS:
        out << MakeNode(node->id, "AssignPlus");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_ASSIGN_MINUS:
        out << MakeNode(node->id, "AssignMinus");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_ASSIGN_LOGICAL_AND:
        out << MakeNode(node->id, "AssignAnd");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_ASSIGN_LOGICAL_OR:
        out << MakeNode(node->id, "AssignOr");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;

    case ExpressionType::_EQUAL:
        out << MakeNode(node->id, "Equal");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_NOT_EQUAL:
        out << MakeNode(node->id, "NotEqual");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_STRICT_EQUAL:
        out << MakeNode(node->id, "StrictEqual");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_STRICT_NOT_EQUAL:
        out << MakeNode(node->id, "StrictNotEqual");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_LESS_EQUAL:
        out << MakeNode(node->id, "LessEqual");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_GREAT_EQUAL:
        out << MakeNode(node->id, "GreaterEqual");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;

    case ExpressionType::_COMMA:
        out << MakeNode(node->id, "CommaOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_INSTANCEOF:
        out << MakeNode(node->id, "InstanceofOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_IN:
        out << MakeNode(node->id, "InOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id);
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id);
        break;
    case ExpressionType::_TERNARY:
        out << MakeNode(node->id, "Ternary");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id, "condition");
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id, "ifTrue");
        ToDot(node->thirdOperand, out);
        out << MakeConnection(node->id, node->thirdOperand->id, "ifFalse");
        break;

    case ExpressionType::_ARRAY_CREATION:
        out << MakeNode(node->id, "ArrayCreation");
        if (node->params != NULL) {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        break;
    case ExpressionType::_ARRAY_EMPTY_ELEMENT:
        out << MakeNode(node->id, "ArrayEmptyElement");
        break;
    case ExpressionType::_ARRAY_ACCESS:
        out << MakeNode(node->id, "ArrayAccess");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id, "array");
        ToDot(node->secondOperand, out);
        out << MakeConnection(node->id, node->secondOperand->id, "index");
        break;

    case ExpressionType::_FUNC_CALL:
        out << MakeNode(node->id, "FuncCall:\nFuncName: " + std::string{node->identifierString});
        if (node->params != NULL) {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        break;
    case ExpressionType::_SUPER_CALL:
        out << MakeNode(node->id, "SuperCall");
        if (node->params != NULL) {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        break;
    case ExpressionType::_FIELD_ACCESS:
        out << MakeNode(node->id,
                        "FieldAccess:\nFieldName: " + std::string{node->identifierString});
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id, "object");
        break;
    case ExpressionType::_METHOD_ACCESS:
        out << MakeNode(node->id,
                        "MethodAccess\nMethodName: " + std::string{node->identifierString});
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id, "object");
        if (node->params != NULL) {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        break;
    case ExpressionType::_NEW:
        out << MakeNode(node->id, "NewOperator");
        ToDot(node->firstOperand, out);
        out << MakeConnection(node->id, node->firstOperand->id, "construct");

        if (node->params != NULL) {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        break;
    default:
        break;
    }
}

void ToDot(StatementNode *node, std::ostream &out) {
    std::string name;
    switch (node->type) {
    case StatementType::_EMPTY:
        out << MakeNode(node->id, "EmptyStmtNode");
        break;
    case StatementType::_EXPRESSION:
        out << MakeNode(node->id, "ExprStmtNode");
        ToDot(node->expression, out);
        out << MakeConnection(node->id, node->expression->id);
        break;
    case StatementType::_VAR:
        name = "VarStmtNode\nModifierType: " + ToString(node->modifierType);
        out << MakeNode(node->id, name);

        if (node->declList != NULL) {
            ToDot(node->declList, out);
            out << MakeConnection(node->id, node->declList->id);
        }
        break;
    case StatementType::_RETURN:
        out << MakeNode(node->id, "ReturnStmtNode");

        if (node->expression != NULL) {
            ToDot(node->expression, out);
            out << MakeConnection(node->id, node->expression->id);
        }
        break;
    case StatementType::_BLOCK:
        out << MakeNode(node->id, "BlockStmtNode");

        if (node->stmtList != NULL) {
            ToDot(node->stmtList, out);
            out << MakeConnection(node->id, node->stmtList->id);
        }
        break;
    case StatementType::_IFELSE:
        out << MakeNode(node->id, "IfElseStmtNode");
        ToDot(node->expression, out);
        out << MakeConnection(node->id, node->expression->id, "condition");

        ToDot(node->ifBody, out);
        out << MakeConnection(node->id, node->ifBody->id, "ifBody");

        if (node->elseBody != NULL) {
            ToDot(node->elseBody, out);
            out << MakeConnection(node->id, node->elseBody->id, "elseBody");
        }
        break;
    case StatementType::_DOWHILE:
        out << MakeNode(node->id, "DoWhileStmtNode");
        ToDot(node->iterationBody, out);
        out << MakeConnection(node->id, node->iterationBody->id, "body");

        ToDot(node->expression, out);
        out << MakeConnection(node->id, node->expression->id, "condition");
        break;
    case StatementType::_WHILE:
        out << MakeNode(node->id, "WhileStmtNode");
        ToDot(node->iterationBody, out);
        out << MakeConnection(node->id, node->iterationBody->id, "body");

        ToDot(node->expression, out);
        out << MakeConnection(node->id, node->expression->id, "condition");
        break;
    case StatementType::_FOR:
        out << MakeNode(node->id, "ForStmtNode");
        ToDot(node->iterationBody, out);
        out << MakeConnection(node->id, node->iterationBody->id, "body");

        if (node->expression != NULL) {
            ToDot(node->expression, out);
            out << MakeConnection(node->id, node->expression->id, "expr");
        }

        if (node->iterationExprAdd1 != NULL) {
            ToDot(node->iterationExprAdd1, out);
            out << MakeConnection(node->id, node->iterationExprAdd1->id, "exprAdd1");
        }

        if (node->iterationExprAdd2 != NULL) {
            ToDot(node->iterationExprAdd2, out);
            out << MakeConnection(node->id, node->iterationExprAdd2->id, "exprAdd2");
        }

        if (node->declList != NULL) {
            ToDot(node->declList, out);
            out << MakeConnection(node->id, node->declList->id, ToString(node->modifierType));
        }

        if (node->decl != NULL) {
            ToDot(node->decl, out);
            out << MakeConnection(node->id, node->decl->id, ToString(node->modifierType));
        }
        break;
    default:
        break;
    }
}

void ToDot(StatementListNode *node, std::ostream &out) {
    out << MakeNode(node->id, "StatementListNode");

    StatementNode *child = node->first;
    while (child != NULL) {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
        child = child->next;
    }
}

void ToDot(RequiredParameterNode *node, std::ostream &out) {
    out << MakeNode(node->id, "RequiredParameterNode\nName: " + std::string{node->paramName});

    if (node->paramType != NULL) {
        ToDot(node->paramType, out);
        out << MakeConnection(node->id, node->paramType->id, "type");
    }
}

void ToDot(RequiredParameterListNode *node, std::ostream &out) {
    out << MakeNode(node->id, "RequiredParameterListNode");

    RequiredParameterNode *child = node->first;
    while (child != NULL) {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
        child = child->next;
    }
}

void ToDot(FunctionDeclarationNode *node, std::ostream &out) {
    out << MakeNode(node->id, "FunctionDeclarationNode\nName: " + std::string{node->funcName});

    if (node->params != NULL) {
        ToDot(node->params, out);
        out << MakeConnection(node->id, node->params->id, "params");
    }

    if (node->returnType != NULL) {
        ToDot(node->returnType, out);
        out << MakeConnection(node->id, node->returnType->id, "returnType");
    }

    if (node->body != NULL) {
        ToDot(node->body, out);
        out << MakeConnection(node->id, node->body->id, "body");
    }
}

void ToDot(ClassElementNode *node, std::ostream &out) {
    switch (node->type) {
    case ClassElementType::_CONSTRUCTOR:
        out << MakeNode(node->id, "ClassConstructorNode");
        if (node->params != NULL) {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }
        if (node->methodBody != NULL) {
            ToDot(node->methodBody, out);
            out << MakeConnection(node->id, node->methodBody->id, "body");
        }
        break;
    case ClassElementType::_PROPERTY:
        out << MakeNode(node->id, "ClassPropertyNode\nName: " + std::string{node->name});

        if (node->propertyAndReturnType != NULL) {
            ToDot(node->propertyAndReturnType, out);
            out << MakeConnection(node->id, node->propertyAndReturnType->id, "type");
        }

        if (node->expression != NULL) {
            ToDot(node->expression, out);
            out << MakeConnection(node->id, node->expression->id, "init");
        }
        break;
    case ClassElementType::_METHOD:
        out << MakeNode(node->id, "ClassMethodNode\nName: " + std::string{node->name});
        if (node->params != NULL) {
            ToDot(node->params, out);
            out << MakeConnection(node->id, node->params->id, "params");
        }

        if (node->propertyAndReturnType != NULL) {
            ToDot(node->propertyAndReturnType, out);
            out << MakeConnection(node->id, node->propertyAndReturnType->id, "type");
        }

        if (node->methodBody != NULL) {
            ToDot(node->methodBody, out);
            out << MakeConnection(node->id, node->methodBody->id, "body");
        }
        break;
    default:
        break;
    }
}

void ToDot(ClassElementListNode *node, std::ostream &out) {
    out << MakeNode(node->id, "ClassElementListNode");

    ClassElementNode *child = node->first;
    while (child != NULL) {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
        child = child->next;
    }
}

void ToDot(ClassDeclarationNode *node, std::ostream &out) {
    std::string name = "ClassDeclarationNode\nName: " + std::string{node->className};
    if (node->heritageName != NULL) {
        name += "\\nHeritage: " + std::string{node->heritageName};
    }
    out << MakeNode(node->id, name);

    if (node->body != NULL) {
        ToDot(node->body, out);
        out << MakeConnection(node->id, node->body->id, "body");
    }
}

void ToDot(TSElementNode *node, std::ostream &out) {
    out << MakeNode(node->id, "TSElementNode");

    switch (node->type) {
    case TSElementType::_STATEMENT:
        ToDot(node->stmt, out);
        out << MakeConnection(node->id, node->stmt->id);
        break;
    case TSElementType::_FUNCTION:
        ToDot(node->funcDecl, out);
        out << MakeConnection(node->id, node->funcDecl->id);
        break;
    case TSElementType::_CLASS:
        ToDot(node->classDecl, out);
        out << MakeConnection(node->id, node->classDecl->id);
        break;
    default:
        break;
    }
}

void ToDot(TSElementListNode *node, std::ostream &out) {
    out << MakeNode(node->id, "TSElementListNode");

    TSElementNode *child = node->first;
    while (child != NULL) {
        ToDot(child, out);
        out << MakeConnection(node->id, child->id);
        child = child->next;
    }
}

void ToDot(TSScriptNode *node, std::ostream &out) {
    out << "digraph TSScript {\n";
    out << MakeNode(node->id, "Script");

    if (node->elemList != NULL) {
        ToDot(node->elemList, out);
        out << MakeConnection(node->id, node->elemList->id);
    }
    out << "}" << std::endl;
}