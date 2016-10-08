#ifndef list_buffer_h
#define list_buffer_h

#include "text_out_buffer.h"
#include "text_in_buffer.h"

extern int listFlag;

class ListBuffer : public TextOutBuffer {
	char *pSourceFileName;
	char date[26];
	int pageNumber;
	int lineCount;

	void printPageHeader();

public:
	virtual ~ListBuffer()
	{
		delete pSourceFileName;
	}

	void initialize(const char *fileName);
	virtual void putLine();

	void putLine(const char *pText)
	{
		TextOutBuffer::putLine(pText);
	}

	void putLine(const char *pText, int lineNumber, int nestingLevel)
	{
		sprintf(text, "%4d %d: %s", lineNumber, nestingLevel, pText);
		putLine();
	}
};

extern ListBuffer list;

#endif