#include "source_buffer.h"
#include <iostream>

SourceBuffer::SourceBuffer(const char *sourceFileName) : TextInBuffer(sourceFileName, sourceFileOpenFailed)
{
	
}

char SourceBuffer::getLine()
{
	extern int lineNumber;

	if (file.eof())
	{
		pChar = &eofChar;
	} else {
		file.getline(text, maxInputBufferSize);
		pChar = text;

		if (listFlag)
		{
			// TODO
		}
	}

	std::cout << pChar << std::endl;

	inputPosition = 0;

	return *pChar;
}