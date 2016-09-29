#include "TextInBuffer.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>

char eofChar = 0x7F;

TextInBuffer::TextInBuffer(const char *pInputFileName, ErrorCode errorCode) : pFileName(new char[strlen(pInputFileName) + 1])
{
	strcpy(pFileName, pInputFileName);

	file.open(pFileName, std::ios::in);

	if (!file.good())
	{
		abort(errorCode);	
	}
}

char TextInBuffer::getChar()
{

}