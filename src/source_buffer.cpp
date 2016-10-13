#include "source_buffer.h"
#include <iostream>

#include "common.h"
#include "list_buffer.h"

SourceBuffer::SourceBuffer(const char *sourceFileName) : TextInBuffer(sourceFileName, sourceFileOpenFailed)
{
	if (listFlag) list.initialize(sourceFileName);
	getLine();
}

char SourceBuffer::getLine()
{
	extern int lineNumber, currentNestingLevel;

	if (file.eof()) {
		pChar = &eofChar;
	} else {
		file.getline(text, maxInputBufferSize);
		pChar = text;

		if (listFlag) {
			list.putLine(text, ++currentLineNumber, currentNestingLevel);
		}
	}

	inputPosition = 0;

	return *pChar;
}