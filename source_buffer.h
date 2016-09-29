#ifndef source_buffer_h
#define source_buffer_h

#include "TextInBuffer.h"

extern char inputPosition;
extern int listFlag;

class SourceBuffer : public TextInBuffer {
	virtual char getLine();
public:
	SourceBuffer(const char *sourceFileName);	
};

#endif