#ifndef line_num_list_h
#define line_num_list_h

#include "line_num_node.h"

class LineNumList {
	LineNumNode *head, *tail;
public:
	LineNumList() {
		head = tail = new LineNumNode;
	}
	virtual ~LineNumList();

	void update();
	void print(int newLineFlag, int indent) const;
};

#endif