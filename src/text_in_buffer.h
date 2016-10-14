#ifndef text_in_buffer_h
#define text_in_buffer_h

#include <fstream>
#include "errors.h"

extern char eofChar;

const int maxInputBufferSize = 256;

class TextInBuffer {
protected:
	std::fstream file;
	char *const pFileName;
	char text[maxInputBufferSize];
	char *pChar;
	virtual char getLine() = 0;
public:
	TextInBuffer(const char *pInputFileName, AbortCode abortCode);

	virtual ~TextInBuffer()
	{
		file.close();
		delete[] pFileName;
	}

	char getChar();
	char Char() const { return *pChar; }
	char putBackChar();
};

#endif