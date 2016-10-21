#ifndef compact_list_buffer_h
#define compact_list_buffer_h

#include "text_out_buffer.h"

const int maxCompactTextLength = 72;

class CompactListBuffer : public TextOutBuffer {
	int textLength;
	char *pText;
public:
	CompactListBuffer() {
		pText = text;
		*pText = '\0';
		textLength = 0;
	}

	virtual ~CompactListBuffer() {}

	void putBlank();
	void put(const char *pString);
	void putLine();
};

#endif