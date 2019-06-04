#include "symbol_table.h"

int xrefFlag = true;

SymbolTableNode *SymbolTable::search(const char *pString) const
{
	SymbolTableNode *pNode = rootNode;
	int comp;

	while (pNode)
	{
		comp = strcmp(pString, pNode->pSymbolString);
		if (comp == 0)
		{
			break;
		}

		pNode = comp < 0 ? pNode->leftNode : pNode->rightNode;
	}

	if (xrefFlag && (comp == 0))
	{
		pNode->pLineNumList->update();
	}

	return pNode;
}

SymbolTableNode *SymbolTable::enter(const char *pString)
{
	SymbolTableNode *pNode;
	SymbolTableNode **ppNode = &rootNode;

	while ((pNode = *ppNode) != NULL)
	{
		int comp = strcmp(pString, pNode->pSymbolString);

		if (comp == 0)
		{
			return pNode;
		}

		ppNode = comp < 0 ? &(pNode->leftNode) : &(pNode->rightNode);
	}

	pNode = new SymbolTableNode(pString);
	pNode->symbolTableIndex = symbolTableIndex;
	pNode->nodeIndex = nodeCount++;
	*ppNode = pNode;

	return pNode;
}