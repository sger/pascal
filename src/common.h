#ifndef common_h
#define common_h

#include "misc.h"
#include "symbol_table.h"

extern int currentLineNumber;
extern int currentNestingLevel;
extern SymbolTable globalSymbolTable;
extern SymbolTable *pSymbolTableList;
extern int cntSymtabs;

#endif