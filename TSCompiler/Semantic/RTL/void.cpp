#include "../semantic.h"

ClassDeclarationNode *Semantic::createVoidClass()
{
    auto *body = ClassElementListNode::makeEmpty();

    {
        auto *clsConstructor = new ClassElementNode(
            RequiredParameterListNode::makeEmpty(), nullptr);
        body->add(clsConstructor);
        clsConstructor->propertyAndReturnType =
            new TypeNode(new JvmDataType(JvmDataType::Type::Void));
    }

    // Methods

    // Plus

    std::vector<JvmDataType> types = {RTL_NULL_TYPE, RTL_VOID_TYPE};

    {
        auto *type = new TypeNode(new JvmDataType(RTL_STRING_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "plus", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_STRING_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_NULL_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "plus", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_NUMBER_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }
    {
        auto *type = new TypeNode(new JvmDataType(RTL_UNDEFINED_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "plus", new RequiredParameterListNode(param),
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

    for (const auto &jvmType : types)
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

    for (const auto &jvmType : types)
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

    for (const auto &jvmType : types)
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

    for (const auto &jvmType : types)
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

    for (const auto &jvmType : types)
    {
        auto *type = new TypeNode(new JvmDataType(jvmType));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "lessEqual", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }

    for (const auto &jvmType : types)
    {
        auto *type = new TypeNode(new JvmDataType(jvmType));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "greatEqual", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }

    auto *rtlClass = new ClassDeclarationNode("JavaRTL/Void", "Any", body);
    for (auto *elem : body->GetSeq()) elem->elemClass = rtlClass;
    return rtlClass;
}
