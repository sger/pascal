#include "text_in_buffer.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>

char eofChar = 0x7F;
int inputPosition;
int listFlag = true;

TextInBuffer::TextInBuffer(const char *pInputFileName, AbortCode abortCode) : pFileName(new char[strlen(pInputFileName) + 1])
{
	strcpy(pFileName, pInputFileName);

	file.open(pFileName, std::ios::in);

	if (!file.good())
	{
		abort(abortCode);	
	}
}

char TextInBuffer::getChar()
{
	const int tabSize = 8;
	char ch;

	if (*pChar == eofChar) {
		return eofChar;
	} else if (*pChar == '\0') {
		ch = getLine();
	} else {
		++pChar;
		++inputPosition;
		ch = *pChar;
	}

	if (ch == '\t') {
		inputPosition += tabSize - inputPosition % tabSize;
	}

	return ch;
}

char TextInBuffer::putBackChar()
{
	--pChar;
	--inputPosition;

	return *pChar;
}