#include "symbol_table.h"

#include "errors.h"

int asmLabelIndex = 0;
int xrefFlag = false;

SymbolTableNode *SymbolTable::search(const char *pString) const {
  SymbolTableNode *pNode = rootNode;
  int comp;

  while (pNode) {
    comp = strcmp(pString, pNode->pSymbolString);
    if (comp == 0) {
      break;
    }

    pNode = comp < 0 ? pNode->leftNode : pNode->rightNode;
  }

  if (xrefFlag && (comp == 0)) {
    pNode->pLineNumList->update();
  }

  return pNode;
}

SymbolTableNode *SymbolTable::enter(const char *pString, TypeDefCode dc) {
  SymbolTableNode *pNode;
  SymbolTableNode **ppNode = &rootNode;

  while ((pNode = *ppNode) != NULL) {
    int comp = strcmp(pString, pNode->pSymbolString);

    if (comp == 0) {
      return pNode;
    }

    ppNode = comp < 0 ? &(pNode->leftNode) : &(pNode->rightNode);
  }

  pNode = new SymbolTableNode(pString, dc);
  pNode->symbolTableIndex = symbolTableIndex;
  pNode->nodeIndex = nodeCount++;
  *ppNode = pNode;

  return pNode;
}

SymbolTableNode *SymbolTable::enterNew(const char *pString, TypeDefCode dc) {
  SymbolTableNode *pNode = search(pString);

  if (!pNode) {
    pNode = enter(pString, dc);
  } else {
    displayError(errorRedefinedIdentifier);
  }

  return pNode;
}

void SymbolTable::convert(SymbolTable *vpSymtabs[]) {
  vpSymtabs[symbolTableIndex] = this;

  vpNodes = new SymbolTableNode *[nodeCount];
  rootNode->convert(vpNodes);
}