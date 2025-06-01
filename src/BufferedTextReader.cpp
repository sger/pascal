#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>

#include "BufferedTextReader.h"
#include "Constants.h"
#include "Globals.h"

BufferedTextReader::BufferedTextReader(const char* pInputFileName, AbortCode abortCode)
    : pFileName(pInputFileName)
{
    file.open(pFileName, std::ios::in);

    if (!file.is_open())
    {
        abortTranslation(abortCode);
    }
}

BufferedTextReader::~BufferedTextReader()
{
    if (file.is_open())
    {
        file.close();
    }
}

auto BufferedTextReader::getChar() -> char
{
    const int tabSize = 8;
    char nextChar;

    if (*pChar == EOF_CHAR)
    {
        return EOF_CHAR;
    }

    if (*pChar == '\0')
    {
        nextChar = getLine();
    }
    else
    {
        ++pChar;
        ++inputPosition;
        nextChar = *pChar;
    }

    if (nextChar == '\t')
    {
        inputPosition += tabSize - inputPosition % tabSize;
    }

    return nextChar;
}

auto BufferedTextReader::putBackChar() -> char
{
    --pChar;
    --inputPosition;

    return *pChar;
}