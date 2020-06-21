#include "types.h"
#include "list_buffer.h"

const char *formStrings[] = {"*** Error ***", "Scalar", "Enumeration", "Subrange", "Array", "Record"};

Type *pIntegerType = NULL;
Type *pRealType = NULL;
Type *pBooleanType = NULL;
Type *pCharType = NULL;
Type *pDummyType = NULL;

Type::Type(FormCode formCode, int s, SymbolTableNode *pId)
{
    form = formCode;
    size = s;
    pTypeId = pId;
    referenceCount = 0;

    switch (formCode)
    {
    case fcSubrange:
        subrange.pBaseType = NULL;
        break;
    case fcArray:
        array.pIndexType = array.pElmtType = NULL;
        break;

    default:
        break;
    }
}

Type::Type(int length)
{
    form = fcArray;
    size = length;
    pTypeId = NULL;
    referenceCount = 0;

    array.pIndexType = array.pElmtType = NULL;
    setType(array.pIndexType, new Type(fcSubrange, sizeof(int), NULL));
    setType(array.pElmtType, pCharType);
    array.elmtCount = length;

    setType(array.pIndexType->subrange.pBaseType, pIntegerType);
    array.pIndexType->subrange.min = 1;
    array.pIndexType->subrange.max = length;
}

Type::~Type(void)
{
    switch (form)
    {
    case fcSubrange:
        removeType(subrange.pBaseType);
        break;
    case fcArray:
        removeType(array.pIndexType);
        removeType(array.pElmtType);
        break;
    case fcRecord:
        delete record.pSymtab;
        break;
    default:
        break;
    }
}

void Type::printTypeSpec(VerbosityCode vc) const
{
    sprintf(list.text, "%s, size %d bytes. Type identifier: ", formStrings[form], size);

    if (pTypeId)
    {
        strcat(list.text, pTypeId->getSymbolString());
    }
    else
    {
        strcat(list.text, "<unnamed>");
        vc = vcVerbose;
    }
    list.putLine();

    switch (form)
    {
    case fcEnum:
        printEnumType(vc);
        break;
    case fcSubrange:
        printSubrangeType(vc);
        break;
    case fcArray:
        printArrayType(vc);
        break;
    case fcRecord:
        printRecordType(vc);
        break;
    default:
        break;
    }
}

void Type::printEnumType(VerbosityCode vc) const
{
    if (vc == vcTerse)
    {
        return;
    }

    list.putLine("--- Enumeration Constant Identifiers "
                 "(value = name) ---");

    for (SymbolTableNode *pConstId = enumeration.pConstIds;
         pConstId; pConstId = pConstId->next)
    {
        // sprintf(list.text, "    %d = %s",
        //         pConstId->defn.constant.value.integer,
        //         pConstId->getSymbolString());
        // list.putLine();
    }
}

void Type::printSubrangeType(VerbosityCode vc) const
{
}
void Type::printArrayType(VerbosityCode vc) const
{
}
void Type::printRecordType(VerbosityCode vc) const
{
}

Type *setType(Type *&pTargetType, Type *pSourceType)
{
}

void removeType(Type *&pType)
{
}

void checkRelOpOperands(const Type *pType1, const Type *pType2) {}
void checkAssignmentCompatible(const Type *pTargetType, const Type *pValueType, ErrorCode ec) {}

int integerOperands(const Type *pType1, const Type *pType2) {}
int realOperands(const Type *pType1, const Type *pType2) {}

void initializePredefinedTypes(SymbolTable *pSymbolTable)
{
}
void removePredefinedTypes(void)
{
}