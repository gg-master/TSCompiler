#include "semantic.h"

ClassDeclarationNode *Semantic::createAnyClass()
{
    auto *body = ClassElementListNode::makeEmpty();

    {
        auto *clsConstructor = new ClassElementNode(
            RequiredParameterListNode::makeEmpty(), nullptr);
        body->add(clsConstructor);
        clsConstructor->propertyAndReturnType =
            new TypeNode(new JvmDataType(JvmDataType::Type::Void));
    }

    {
        auto *method = new ClassElementNode(
            "length", RequiredParameterListNode::makeEmpty(),
            new TypeNode(new JvmDataType(RTL_ANY_TYPE)), nullptr, false);
        body->add(method);
    }

    {
        auto *type = new TypeNode(new JvmDataType(RTL_ANY_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "plus", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_ANY_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }

    for (const auto &operation :
         std::vector<std::string>{"minus", "mul", "div"})
    {
        auto *type = new TypeNode(new JvmDataType(RTL_ANY_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            operation, new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_NUMBER_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }

    for (const auto &operation : std::vector<std::string>{
             "equal", "notEqual", "lessEqual", "greatEqual", "less", "great"})
    {
        auto *type = new TypeNode(new JvmDataType(RTL_ANY_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            operation, new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_BOOLEAN_TYPE)), nullptr);
        method->analyzeArguments();
        body->add(method);
    }

    {
        auto *method = new ClassElementNode(
            "uPlus", RequiredParameterListNode::makeEmpty(),
            new TypeNode(new JvmDataType(RTL_ANY_TYPE)), nullptr);
        body->add(method);
    }
    {
        auto *method = new ClassElementNode(
            "uMinus", RequiredParameterListNode::makeEmpty(),
            new TypeNode(new JvmDataType(RTL_NUMBER_TYPE)), nullptr);
        body->add(method);
    }

    auto *rtlClass = new ClassDeclarationNode("JavaRTL/Any", body);
    for (auto *elem : body->GetSeq()) elem->elemClass = rtlClass;
    return rtlClass;
}

ClassDeclarationNode *Semantic::createConsoleClass()
{
    auto *body = ClassElementListNode::makeEmpty();

    {
        auto *clsConstructor = new ClassElementNode(
            RequiredParameterListNode::makeEmpty(), nullptr);
        clsConstructor->analyzeArguments();
        body->add(clsConstructor);
        clsConstructor->propertyAndReturnType =
            new TypeNode(new JvmDataType(JvmDataType::Type::Void));
    }

    // Methods
    {
        auto *type = new TypeNode(new JvmDataType(RTL_ANY_TYPE));
        auto *param = new RequiredParameterNode("other", type);
        auto *method = new ClassElementNode(
            "log", new RequiredParameterListNode(param),
            new TypeNode(new JvmDataType(RTL_VOID_TYPE)), nullptr, true);
        method->analyzeArguments();
        body->add(method);
    }

    {
        auto *method = new ClassElementNode(
            "readLine", RequiredParameterListNode::makeEmpty(),
            new TypeNode(new JvmDataType(RTL_STRING_TYPE)), nullptr, true);
        body->add(method);
    }

    auto *rtlClass = new ClassDeclarationNode("JavaRTL/Console", body);
    for (auto *elem : body->GetSeq()) elem->elemClass = rtlClass;
    return rtlClass;
}
