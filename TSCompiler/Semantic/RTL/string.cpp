#include "../semantic.h"

ClassDeclarationNode *Semantic::createStringClass()
{
    auto *body = ClassElementListNode::makeEmpty();

    // Class constructors
    {
        auto *clsConstructor = new ClassElementNode(
            RequiredParameterListNode::makeEmpty(), nullptr);
        clsConstructor->analyzeArguments();
        body->add(clsConstructor);
        clsConstructor->propertyAndReturnType =
            new TypeNode(new JvmDataType(JvmDataType::Type::Void));
    }

    std::vector<JvmDataType> types = {JvmDataType(JvmDataType::Type::Double),
                                      JvmDataType(JvmDataType::Type::Int),
                                      JvmDataType(JvmDataType::Type::String),
                                      RTL_ANY_TYPE};

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
        auto *type = new TypeNode(new JvmDataType(RTL_ANY_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "plus", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_STRING_TYPE)), nullptr);
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

    std::vector<JvmDataType> operationTypes = {RTL_STRING_TYPE, RTL_NULL_TYPE,
                                               RTL_UNDEFINED_TYPE};

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

    auto *rtlClass = new ClassDeclarationNode("JavaRTL/String", body);
    for (auto *elem : body->GetSeq()) elem->elemClass = rtlClass;
    return rtlClass;
}
