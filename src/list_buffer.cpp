#include "list_buffer.h"
#include <iostream>

const int maxPrintLineLength = 80;
const int maxLinesPerPage = 50;

ListBuffer list;

void ListBuffer::printPageHeader()
{
	const char formFeedChar = '\f';

	std::cout << formFeedChar << "Page " << ++pageNumber << "	" << pSourceFileName << "	" << date << std::endl << std::endl;

	lineCount = 0;
}

void ListBuffer::initialize(const char *pFileName)
{
	text[0] = '\0';
	pageNumber = 0;

	pSourceFileName = new char[strlen(pFileName) + 1];
	strcpy(pSourceFileName, pFileName);

	time_t timer;
    time(&timer);
    strcpy(date, asctime(localtime(&timer)));
    date[strlen(date) - 1] = '\0';  

    printPageHeader();
}

void ListBuffer::putLine()
{
	if (listFlag && (lineCount == maxLinesPerPage))
	{
		printPageHeader();
	}

	text[maxPrintLineLength] = '\0';

	std::cout << text << std::endl;
	text[0] = '\0';

	++lineCount;
}