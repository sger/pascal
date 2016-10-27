#include "symbol_table_node.h"

#include <stdio.h>
#include <string.h>

#include "list_buffer.h"

SymbolTableNode::SymbolTableNode(const char *pStr) {
	leftNode = NULL;
	rightNode = NULL;
	value = 0.0;
	nodeIndex = 0;

	pSymbolString = new char[strlen(pStr) + 1];
	strcpy(pSymbolString, pStr);
	
	if (xrefFlag) {
		pLineNumList = new LineNumList;
	}
}

SymbolTableNode::~SymbolTableNode() {
	delete leftNode;
	delete rightNode;

	delete[] pSymbolString;
}

void SymbolTableNode::print() const {
	const int maxNamePrintWidth = 16;

	if (leftNode)
	{
		leftNode->print();
	}

	sprintf(list.text, "%*s", maxNamePrintWidth, pSymbolString);

	if (pLineNumList)
	{
		pLineNumList->print(strlen(pSymbolString) > maxNamePrintWidth, maxNamePrintWidth);
	}
	else
	{
		list.putLine();
	}

	if (rightNode)
	{
		rightNode->print();
	}
}
