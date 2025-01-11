#include "../semantic.h"

ClassDeclarationNode *Semantic::createNumberClass()
{
    auto *body = ClassElementListNode::makeEmpty();

    // Class constructors
    {
        auto *clsConstructor = new ClassElementNode(
            RequiredParameterListNode::makeEmpty(), nullptr);
        body->add(clsConstructor);
        clsConstructor->propertyAndReturnType =
            new TypeNode(new JvmDataType(JvmDataType::Type::Void));
    }

    std::vector<JvmDataType> types = {JvmDataType(JvmDataType::Type::Int),
                                      JvmDataType(JvmDataType::Type::Double),
                                      JvmDataType(JvmDataType::Type::String),
                                      RTL_NUMBER_TYPE,
                                      RTL_BOOLEAN_TYPE,
                                      RTL_STRING_TYPE,
                                      RTL_NULL_TYPE,
                                      RTL_VOID_TYPE};

    for (const auto &jvmType : types)
    {
        auto *type = new TypeNode(new JvmDataType(jvmType));
        auto *param = new RequiredParameterNode("value", type);
        auto *clsConstructor =
            new ClassElementNode(new RequiredParameterListNode(param), nullptr);
        clsConstructor->analyzeArguments();
        body->add(clsConstructor);
        clsConstructor->propertyAndReturnType =
            new TypeNode(new JvmDataType(JvmDataType::Type::Void));
    }

    // Methods

    // Plus
    {
        auto *type = new TypeNode(new JvmDataType(RTL_STRING_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "plus", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_STRING_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }

    std::vector<JvmDataType> operationTypes = {RTL_NUMBER_TYPE, RTL_NULL_TYPE,
                                               RTL_UNDEFINED_TYPE};

    for (const auto &jvmType : operationTypes)
    {
        auto *type = new TypeNode(new JvmDataType(jvmType));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "plus", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_NUMBER_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }

    // Minus

    for (const auto &jvmType : operationTypes)
    {
        auto *type = new TypeNode(new JvmDataType(jvmType));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "minus", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_NUMBER_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }

    // Mul

    for (const auto &jvmType : operationTypes)
    {
        auto *type = new TypeNode(new JvmDataType(jvmType));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "mul", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_NUMBER_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }

    // Div

    for (const auto &jvmType : operationTypes)
    {
        auto *type = new TypeNode(new JvmDataType(jvmType));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "div", new RequiredParameterListNode(param),
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

    // Less

    for (const auto &jvmType : operationTypes)
    {
        auto *type = new TypeNode(new JvmDataType(jvmType));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "less", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }

    // Great

    for (const auto &jvmType : operationTypes)
    {
        auto *type = new TypeNode(new JvmDataType(jvmType));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "great", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }

    // Equal

    for (const auto &jvmType : operationTypes)
    {
        auto *type = new TypeNode(new JvmDataType(jvmType));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "equal", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }

    // NotEqual

    for (const auto &jvmType : operationTypes)
    {
        auto *type = new TypeNode(new JvmDataType(jvmType));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "notEqual", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }

    // LessEqual

    for (const auto &jvmType : operationTypes)
    {
        auto *type = new TypeNode(new JvmDataType(jvmType));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "lessEqual", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }

    // GreatEqual

    for (const auto &jvmType : operationTypes)
    {
        auto *type = new TypeNode(new JvmDataType(jvmType));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "greatEqual", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }

    auto *rtlClass = new ClassDeclarationNode("JavaRTL/Number", body);
    for (auto *elem : body->GetSeq()) elem->elemClass = rtlClass;
    return rtlClass;
}
