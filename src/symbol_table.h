#ifndef symbol_table_h
#define symbol_table_h

#include <iostream>

#include "symbol_table_node.h"

class SymbolTable
{
	SymbolTableNode *rootNode;
	short nodeCount;
	short symbolTableIndex;

public:
	SymbolTable()
	{
		rootNode = NULL;
		nodeCount = 0;
		symbolTableIndex = 0;
	}

	~SymbolTable()
	{
		delete rootNode;
	}

	SymbolTableNode *search(const char *pString) const;
	SymbolTableNode *enter(const char *pString);

	SymbolTableNode *getRootNode() const
	{
		return rootNode;
	}

	int getNodeCount() const
	{
		return nodeCount;
	}

	void print() const
	{
		rootNode->print();
	}
};

#endif