#ifndef source_buffer_h
#define source_buffer_h

#include "text_in_buffer.h"

extern char inputPosition;
extern int listFlag;

class SourceBuffer : public TextInBuffer {
	virtual char getLine();
public:
	SourceBuffer(const char *sourceFileName);	
};

#endif