#pragma once
#include <string>
#include <vector>

#include "../Tree/ts_script.h"

using IdT = uint16_t;
using IntT = std::int32_t;
using DoubleT = double;
using Bytes = std::vector<unsigned char>;

inline void append(Bytes &bytes, Bytes::value_type value)
{
    bytes.push_back(value);
}

inline void append(Bytes &bytes, Bytes const &value)
{
    bytes.insert(bytes.end(), value.begin(), value.end());
}

inline void append(Bytes &bytes, std::string value)
{
    bytes.insert(bytes.end(), value.begin(), value.end());
}

Bytes toBytes(uint32_t n);

Bytes toBytes(uint16_t n);

Bytes toBytes(IntT n);

Bytes toBytes(int16_t n);

struct Constant
{
    enum class TypeT : uint8_t
    {
        Empty = 0,
        Utf8 = 1,
        Integer = 3,
        Double = 6,
        String = 8,
        NameAndType = 12,
        Class = 7,
        FieldRef = 9,
        MethodRef = 10
    } Type{};

    std::string Utf8{};
    IntT Integer{};
    DoubleT Double{};

    IdT Utf8Id{};

    IdT NameId{};
    IdT TypeId{};

    IdT ClassNameId{};

    IdT NameAndTypeId{};
    IdT ClassId{};

    friend bool operator==(const Constant &lhs, const Constant &rhs);

    friend bool operator!=(const Constant &lhs, const Constant &rhs)
    {
        return !(lhs == rhs);
    }

    static Constant CreateUtf8(std::string const &content);

    static Constant CreateInt(IntT i);

    static Constant CreateEmpty();
    static Constant CreateDouble(DoubleT float_);

    static Constant CreateString(IdT Utf8);

    static Constant CreateNaT(IdT nameId, IdT typeId);

    static Constant CreateClass(IdT classNameId);

    static Constant CreateFieldRef(IdT natId, IdT classId);

    static Constant CreateMethodRef(IdT natId, IdT classId);
};

Bytes toBytes(Constant const &constant);

struct ConstantTable
{
    std::vector<Constant> Constants;
    using ConstantRef = Constant const &;

    IdT FindUtf8(std::string utf8);

    IdT FindString(std::string str);

    IdT FindInt(IntT i);

    IdT FindDouble(DoubleT i);

    IdT FindClass(std::string className);

    IdT FindNaT(std::string name, std::string type);

    IdT FindFieldRef(std::string className, std::string name, std::string type);

    IdT FindMethodRef(std::string className, std::string name,
                      std::string type);
};

Bytes toBytes(const ConstantTable &constants);

enum class ArrayType : uint8_t
{
    Boolean = 4,
    Char = 5,
    Float = 6,
    Double = 7,
    Byte = 8,
    Short = 9,
    Int = 10,
    Long = 11
};

enum class AccessFlags : uint16_t
{
    Public = 0x0001,
    Protected = 0x0004,
    Private = 0x0002,
    Static = 0x0008,
    Final = 0x0010,
    Super = 0x0020
};

inline AccessFlags operator|(AccessFlags lhs, AccessFlags rhs)
{
    using Type = std::underlying_type_t<AccessFlags>;
    const auto lhs2 = static_cast<Type>(lhs);
    const auto rhs2 = static_cast<Type>(rhs);
    return static_cast<AccessFlags>(lhs2 | rhs2);
}

struct JvmField
{
    IdT NameId;
    IdT TypeId;
    AccessFlags AccessFlags;
};

Bytes toBytes(JvmField field);

struct JvmMethod
{
    IdT NameId;
    IdT TypeId;
    AccessFlags AccessFlags;
    ClassElementNode *ActualMethod;
};

struct ClassFile
{
    static constexpr uint32_t MagicConstant = 0xCAFEBABE;
    static constexpr uint16_t MinorVersion = 0;
    static constexpr uint16_t MajorVersion = 65;

    AccessFlags AccessFlags = {};
    uint16_t ThisClass = 0;
    uint16_t SuperClass = 0;
    static constexpr uint16_t InterfaceCount = 0;

    ConstantTable Constants;
    std::vector<JvmField> Fields;
    std::vector<JvmMethod> Methods;
};

struct ClassAnalyzer
{
    ClassFile File{};

    TSScriptNode *root;

    ClassElementNode *currentField = nullptr;
    ClassElementNode *currentMethod = nullptr;
    ClassDeclarationNode *currentClass = nullptr;

    std::vector<std::string> errors{};

    int currentScopingLevel = 0;

    void incrementScopingLevel() { currentScopingLevel++; }

    void decrementScopingLevel()
    {
        if (currentMethod && currentScopingLevel > 0)
        {
            for (auto *varDecl : currentMethod->variables)
            {
                if (varDecl->scopingLevel == currentScopingLevel)
                    varDecl->scopingLevel = -2;  // remove from scoping
            }
            currentScopingLevel--;
        }
    }

    explicit ClassAnalyzer(TSScriptNode *root) : root{root} {}

    void attributeClass(ClassDeclarationNode *node);

    void resolveClassConstructor();

    void attributeMemberSignatures();
    void attributeClassProperty(ClassElementNode *node);

    void analyzeClass(ClassDeclarationNode *node);

    void analyzeClassConstructor();
    void analyzeClassFields();
    void analyzeClassMethod(ClassElementNode *node);

    void analyzeStmt(StatementNode *node, StatementListNode *newSeq = nullptr);

    void analyzeReturn(StatementNode *node);
    void analyzeFor(StatementNode *node, StatementListNode *newSeq);
    void analyzeWhileDoWhile(StatementNode *node);
    void analyzeIf(StatementNode *node);

    StatementNode *analyzeVarDeclaration(VarDeclarationNode *node = nullptr);

    ExpressionNode *analyzeExpr(ExpressionNode *node);

    void analyzeSuperCall(ExpressionNode *node);
    void analyzeFuncCall(ExpressionNode *node);
    void analyzeMethodCall(ExpressionNode *node);
    void analyzeNewCall(ExpressionNode *node);

    void analyzeRequiredParam(RequiredParameterNode *param);

    TypeNode *calculateTypeForExpr(ExpressionNode *node);

    static ExpressionNode *replaceAssignmentsOnArrayElements(
        ExpressionNode *node);
    static ExpressionNode *replaceAssignmentsOnField(ExpressionNode *node);

    static ExpressionNode *replaceOperationsOnMethodCall(ExpressionNode *node);

    void validateTypename(JvmDataType *jvmDataType);
    ClassDeclarationNode *findClass(JvmDataType *jvmDataType) const;

    void moveFunctionScopedVarsOnTop();

    void fillTables();
    void fillFieldTables(ClassElementNode *node);
    void fillMethodTables(ClassElementNode *node);

    void generate();

    Bytes toBytes();
};
