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
    // {
    //     auto *type = new TypeNode(new JvmDataType(RTL_ANY_TYPE));
    //     type->jvmType->arrayArity = 1;

    //     auto *param = new RequiredParameterNode("other", type);
    //     auto *method = new ClassElementNode(
    //         "log", new RequiredParameterListNode(param),
    //         new TypeNode(new JvmDataType(RTL_VOID_TYPE)), nullptr, true);
    //     method->analyzeArguments();
    //     body->add(method);
    // }
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
