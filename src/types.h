#ifndef types_h
#define types_h

#include "symbol_table_node.h"
#include "symbol_table.h"
#include "errors.h"

extern Type *pIntegerType, *pRealType, *pBooleanType, *pCharType, *pDummyType;

enum FormCode
{
    fnNone,
    fcScalar,
    fcEnum,
    fcSubrange,
    fcArray,
    fcRecord,
};

extern const char *formStrings[];

class Type
{
    int referenceCount;

public:
    FormCode form;
    int size;
    SymbolTableNode *pTypeId;

    union {
        // Enumeration
        struct
        {
            SymbolTableNode *pConstIds;
            int max;
        } enumeration;

        // Subrange
        struct
        {
            Type *pBaseType;
            int min, max;
        } subrange;
        // Array
        struct
        {
            Type *pIndexType;
            Type *pElmtType;
            int minIndex, maxIndex;
            int elmtCount;
        } array;
        // Record
        struct
        {
            SymbolTable *pSymtab;
        } record;
    };

    Type(FormCode formCode, int s, SymbolTableNode *pId);
    Type(int length);

    ~Type(void);

    int isScalar(void) const
    {
        return (form != fcArray) && (form != fcRecord);
    }

    Type *Base(void) const
    {
        return form == fcSubrange ? subrange.pBaseType : (Type *)this;
    }

    enum VerbosityCode
    {
        vcVerbose,
        vcTerse
    };

    void printTypeSpec(VerbosityCode vc) const;
    void printEnumType(VerbosityCode vc) const;
    void printSubrangeType(VerbosityCode vc) const;
    void printArrayType(VerbosityCode vc) const;
    void printRecordType(VerbosityCode vc) const;

    friend Type *setType(Type *&pTargetType, Type *pSourceType);
    friend void removeType(Type *&pType);

    friend void checkRelOpOperands(const Type *pType1, const Type *pType2);
    friend void checkIntegerOrReal(const Type *pType1, const Type *pType2 = NULL)
    {
    }
    friend void checkBoolean(const Type *pType1, const Type *pType2 = NULL)
    {
    }
    friend void checkAssignmentCompatible(const Type *pTargetType, const Type *pValueType, ErrorCode ec);

    friend int integerOperands(const Type *pType1, const Type *pType2);
    friend int realOperands(const Type *pType1, const Type *pType2);
};

void initializePredefinedTypes(SymbolTable *pSymbolTable);
void removePredefinedTypes(void);

#endif