#ifndef symbol_table_node_h
#define symbol_table_node_h

#include "line_num_list.h"
#include "type_definition.h"

extern int currentLineNumber;
extern int asmLabelIndex;
extern int xrefFlag;

class Type;

class SymbolTableNode
{
	// Pointers to left and right subtrees
	SymbolTableNode *leftNode, *rightNode;
	// Pointer to symbol string
	char *pSymbolString;
	short symbolTableIndex;
	short nodeIndex;
	// Pointer to list of line numbers
	LineNumList *pLineNumList;

	friend class SymbolTable;

public:
	SymbolTableNode *next;
	Type *pType;

	TypeDefinition defn;
	int level;
	int labelIndex;

	SymbolTableNode(const char *pStr, TypeDefCode dc = dcUndefined);
	~SymbolTableNode();

	SymbolTableNode *getLeftSubTree() const
	{
		return leftNode;
	}

	SymbolTableNode *getRightSubTree() const
	{
		return rightNode;
	}

	char *getSymbolString() const
	{
		return pSymbolString;
	}

	short getSymbolTableIndex() const
	{
		return symbolTableIndex;
	}

	short getNodeIndex() const
	{
		return nodeIndex;
	}

	void convert(SymbolTableNode *vpNodes[]);

	void print() const;
	void printIdentifier() const;
	void printConstant() const;
	void printVarOrField() const;
	void printType() const;
};

#endif