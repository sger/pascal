#include "symbol_table_node.h"

#include <stdio.h>
#include <string.h>

SymbolTableNode::SymbolTableNode(const char *pStr) {
	leftNode = NULL;
	rightNode = NULL;
	value = NULL;
	nodeIndex = 0;

	pSymbolString = new char[strlen(pStr) + 1];
	strcpy(pSymbolString, pStr);
	
	if (xrefFlag) {

	}
}

SymbolTableNode::~SymbolTableNode() {
	delete leftNode;
	delete rightNode;

	delete[] pSymbolString;
}

void SymbolTableNode::print() const {

}
