#ifndef text_out_buffer_h
#define text_out_buffer_h

#include "text_in_buffer.h"

class TextOutBuffer {
public:
	char text[maxInputBufferSize + 16];

	virtual void putLine() = 0;

	void putLine(const char *pText)
	{
		strcpy(text, pText);
		putLine();
	}
};

#endif