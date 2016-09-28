#ifndef textIn_buffer_h
#define textIn_buffer_h

#include "errors.h"

extern char eofChar;

class TextInBuffer {
protected:
	virtual char getLine() = 0;
public:
	TextInBuffer(const char *inputFileName, ErrorCode errorCode);

	char getChar();
};

#endif