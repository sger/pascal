#ifndef symbol_table_h
#define symbol_table_h

#include <iostream>

#include "symbol_table_node.h"

class SymbolTable {
public:
	SymbolTableNode *search(const char *pString) const;
	SymbolTableNode *enter(const char *pString);

	void print() const {
		std::cout << "print()" << std::endl;
	}
};

#endif