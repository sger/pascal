#ifndef symbol_table_h
#define symbol_table_h

#include <iostream>

#include "symbol_table_node.h"
#include "type_definition.h"

class SymbolTable
{
	SymbolTableNode *rootNode;
	SymbolTableNode **vpNodes;
	short nodeCount;
	short symbolTableIndex;
	SymbolTable *next;

public:
	SymbolTable()
	{
		extern int cntSymtabs;
		extern SymbolTable *pSymbolTableList;

		rootNode = NULL;
		nodeCount = 0;
		symbolTableIndex = cntSymtabs++;

		next = pSymbolTableList;
		pSymbolTableList = this;
	}

	~SymbolTable()
	{
		delete rootNode;
		delete[] vpNodes;
	}

	SymbolTableNode *search(const char *pString) const;
	SymbolTableNode *enter(const char *pString, TypeDefCode dc = dcUndefined);
	SymbolTableNode *enterNew(const char *pString, TypeDefCode dc = dcUndefined);

	SymbolTableNode *getRootNode() const
	{
		return rootNode;
	}

	SymbolTableNode *get(short xNode) const
	{
		return vpNodes[xNode];
	}

	SymbolTable *getNextNode() const
	{
		return next;
	}

	SymbolTableNode **nodeVector() const
	{
		return vpNodes;
	}

	int getNodeCount() const
	{
		return nodeCount;
	}

	void print() const
	{
		rootNode->print();
	}

	void convert(SymbolTable *vpSymtabs[]);
};

#endif