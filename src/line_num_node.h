#ifndef line_num_node_h
#define line_num_node_h

#include <stdio.h>

extern int currentLineNumber;

class LineNumNode {
	LineNumNode *next;
	const int number;

	friend class LineNumList;
public:
	LineNumNode() : number(currentLineNumber) {
		next = NULL;
	}
};

#endif