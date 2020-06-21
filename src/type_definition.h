#ifndef type_definition_h
#define type_definition_h

#include "misc.h"

class SymbolTable;
class SymbolTableNode;
class TICode;

enum TypeDefCode
{
    dcUndefined,
    dcConstant,
    dcType,
    dcVariable,
    dcField,
    dcValueParm,
    dcVarParm,
    dcProgram,
    dcProcedure,
    dcFunction,
};

enum TypeRoutineCode
{
    rcDeclared,
    rcForward,
    rcRead,
    rcReadln,
    rcWrite,
    rcWriteln,
    rcAbs,
    rcArctan,
    rcChr,
    rcCos,
    rcEof,
    rcEoln,
    rcExp,
    rcLn,
    rcOdd,
    rcOrd,
    rcPred,
    rcRound,
    rcSin,
    rcSqr,
    rcSqrt,
    rcSucc,
    rcTrunc,
};

struct TypeLocalIds
{
    SymbolTableNode *pParmIds;     // ptr to local parm id list
    SymbolTableNode *pConstantIds; // ptr to local constant id list
    SymbolTableNode *pTypeIds;     // ptr to local type id list
    SymbolTableNode *pVariableIds; // ptr to local variable id list
    SymbolTableNode *pRoutineIds;  // ptr to local proc and func id list
};

class TypeDefinition
{
public:
    TypeDefCode how;

    union {

        struct
        {
            DataValue value;
        } constant;

        struct
        {
            TypeRoutineCode which;
            int parameterCount;
            int totalParameterSize;
            int totalLocalSize;
            SymbolTable *pSymbolTable;
            TypeLocalIds locals;
            TICode *pICode;
        } routine;

        struct
        {
            int offset;
        } data;
    };

    TypeDefinition(TypeDefCode dc)
    {
        how = dc;
    }
    ~TypeDefinition();
};

#endif