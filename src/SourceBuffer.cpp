#include "AbortCode.h"
#include "Constants.h"
#include "SourceBuffer.h"
SourceBuffer::SourceBuffer(const char* pSourceFileName)
    : BufferedTextReader(pSourceFileName, sourceFileOpenFailed)
{
}

auto SourceBuffer::getLine() -> char
{
    extern int lineNumber;
    extern int currentNestingLevel;

    if (file.eof())
    {
        text[0] = EOF_CHAR;
        text[1] = '\0';
        pChar = text.data();
    }
    else
    {
        file.getline(text.data(), maxInputBufferSize);
        pChar = text.data();
    }

    return *pChar;
}