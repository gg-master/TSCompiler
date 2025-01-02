#include "semantic.h"

ClassDeclarationNode *Semantic::createNumberClass()
{
    auto *body = ClassElementListNode::makeEmpty();

    // Class constructors
    {
        auto *type = new TypeNode(new JvmDataType(JvmDataType::Type::Int));
        auto *param = new RequiredParameterNode("value", type);
        auto *clsConstructor =
            new ClassElementNode(new RequiredParameterListNode(param), nullptr);
        clsConstructor->analyzeArguments();
        body->add(clsConstructor);
    }
    {
        auto *type = new TypeNode(new JvmDataType(JvmDataType::Type::Float));
        auto *param = new RequiredParameterNode("value", type);
        auto *clsConstructor =
            new ClassElementNode(new RequiredParameterListNode(param), nullptr);
        clsConstructor->analyzeArguments();
        body->add(clsConstructor);
    }
    {
        auto *type = new TypeNode(new JvmDataType(JvmDataType::Type::String));
        auto *param = new RequiredParameterNode("value", type);
        auto *clsConstructor =
            new ClassElementNode(new RequiredParameterListNode(param), nullptr);
        clsConstructor->analyzeArguments();
        body->add(clsConstructor);
    }

    // Methods
    {
        auto *type = new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "plus", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_NUMBER_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "minus", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_NUMBER_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "mul", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_NUMBER_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *method = new ClassElementNode(
            "uPlus", RequiredParameterListNode::makeEmpty(),
            new TypeNode(new JvmDataType(RTL_NUMBER_TYPE)), nullptr);
        body->add(method);
    }
    {
        auto *method = new ClassElementNode(
            "uMinus", RequiredParameterListNode::makeEmpty(),
            new TypeNode(new JvmDataType(RTL_NUMBER_TYPE)), nullptr);
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "less", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "great", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "equal", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "notEqual", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "lessEqual", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "greatEqual", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *method = new ClassElementNode(
            "toString", RequiredParameterListNode::makeEmpty(),
            new TypeNode(new JvmDataType(JvmDataType::Type::String)), nullptr);
        body->add(method);
    }

    auto *rtlClass = new ClassDeclarationNode("JavaRTL/Number", body);
    return rtlClass;
}

ClassDeclarationNode *Semantic::createBooleanClass()
{
    auto *body = ClassElementListNode::makeEmpty();

    // Class constructors
    {
        auto *type = new TypeNode(new JvmDataType(JvmDataType::Type::Bool));
        auto *param = new RequiredParameterNode("value", type);
        auto *clsConstructor =
            new ClassElementNode(new RequiredParameterListNode(param), nullptr);
        clsConstructor->analyzeArguments();
        body->add(clsConstructor);
    }
    {
        auto *type = new TypeNode(new JvmDataType(JvmDataType::Type::Int));
        auto *param = new RequiredParameterNode("value", type);
        auto *clsConstructor =
            new ClassElementNode(new RequiredParameterListNode(param), nullptr);
        clsConstructor->analyzeArguments();
        body->add(clsConstructor);
    }

    // Methods
    {
        auto *type = new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "equal", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "notEqual", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *method = new ClassElementNode(
            "not", RequiredParameterListNode::makeEmpty(),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "or", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "and", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *method = new ClassElementNode(
            "toString", RequiredParameterListNode::makeEmpty(),
            new TypeNode(new JvmDataType(JvmDataType::Type::String)), nullptr);
        body->add(method);
    }

    auto *rtlClass = new ClassDeclarationNode("JavaRTL/Boolean", body);
    return rtlClass;
}

ClassDeclarationNode *Semantic::createStringClass()
{
    auto *body = ClassElementListNode::makeEmpty();

    // Class constructors
    {
        auto *type = new TypeNode(new JvmDataType(JvmDataType::Type::String));
        auto *param = new RequiredParameterNode("value", type);
        auto *clsConstructor =
            new ClassElementNode(new RequiredParameterListNode(param), nullptr);
        clsConstructor->analyzeArguments();
        body->add(clsConstructor);
    }

    // Methods
    {
        auto *method = new ClassElementNode(
            "toString", RequiredParameterListNode::makeEmpty(),
            new TypeNode(new JvmDataType(JvmDataType::Type::String)), nullptr);
        body->add(method);
    }

    auto *rtlClass = new ClassDeclarationNode("JavaRTL/String", body);
    return rtlClass;
}

ClassDeclarationNode *Semantic::createNullClass()
{
    auto *body = ClassElementListNode::makeEmpty();

    // Methods
    {
        auto *method = new ClassElementNode(
            "toString", RequiredParameterListNode::makeEmpty(),
            new TypeNode(new JvmDataType(JvmDataType::Type::String)), nullptr);
        body->add(method);
    }

    auto *rtlClass = new ClassDeclarationNode("JavaRTL/Null", body);
    return rtlClass;
}

ClassDeclarationNode *Semantic::createUndefinedClass()
{
    auto *body = ClassElementListNode::makeEmpty();

    // Methods
    {
        auto *method = new ClassElementNode(
            "toString", RequiredParameterListNode::makeEmpty(),
            new TypeNode(new JvmDataType(JvmDataType::Type::String)), nullptr);
        body->add(method);
    }

    auto *rtlClass = new ClassDeclarationNode("JavaRTL/Undefined", body);
    return rtlClass;
}

ClassDeclarationNode *Semantic::createConsoleClass()
{
    auto *body = ClassElementListNode::makeEmpty();

    // Methods
    {
        auto *type = new TypeNode(new JvmDataType(RTL_NUMBER_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "log", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_UNDEFINED_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_STRING_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "log", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_UNDEFINED_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "log", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_UNDEFINED_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_NULL_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "log", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_UNDEFINED_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_UNDEFINED_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "log", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_UNDEFINED_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *method = new ClassElementNode(
            "readLine", RequiredParameterListNode::makeEmpty(),
            new TypeNode(new JvmDataType(RTL_STRING_TYPE)), nullptr);
        body->add(method);
    }

    auto *rtlClass = new ClassDeclarationNode("JavaRTL/Console", body);
    return rtlClass;
}
