#ifndef symbol_table_node_h
#define symbol_table_node_h

extern int xrefFlag;

class SymbolTableNode {
	SymbolTableNode *leftNode, *rightNode;
	char *pSymbolString;
	short symbolTableIndex;
	short nodeIndex;

public:
	float value;

	SymbolTableNode(const char *pStr);
	~SymbolTableNode();

	SymbolTableNode *getLeftSubTree() const {
		return leftNode;
	}

	SymbolTableNode *getRightSubTree() const {
		return rightNode;
	}

	char *getSymbolString() const {
		return pSymbolString;
	}

	short getSymbolTableIndex() const {
		return symbolTableIndex;
	}

	short getNodeIndex() const {
		return nodeIndex;
	}

	void print() const;
};

#endif