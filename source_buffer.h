#ifndef source_buffer_h
#define source_buffer_h

#include "TextInBuffer.h"

class SourceBuffer : public TextInBuffer {
	virtual char getLine();
public:
	SourceBuffer(const char *sourceFileName);	
};

#endif