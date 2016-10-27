#ifndef symbol_table_h
#define symbol_table_h

class SymbolTableNode {
	SymbolTableNode *leftNode, *rightNode;
	char *pSymbolString;
	short symbolTableIndex;
	short nodeIndex;

	friend class SymbolTable;
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

	short *getSymbolTableIndex() const {
		return symbolTableIndex;
	}

	short *getNodeIndex() const {
		return nodeIndex;
	}

	void print() const;
};

#endif