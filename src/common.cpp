#include "common.h"

int currentNestingLevel = 0;
int currentLineNumber = 0;
int cntSymtabs = 0;

SymbolTable globalSymbolTable;
extern SymbolTable *pSymbolTableList = NULL;