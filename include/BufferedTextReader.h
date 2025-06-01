#ifndef BUFFERED_TEXT_READER_H
#define BUFFERED_TEXT_READER_H

#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

enum AbortCode {};

const int maxInputBufferSize = 256;

class BufferedTextReader {
protected:
    fstream file;
    char *const pFileName;
    char text[maxInputBufferSize];
    char *pChar;

    virtual auto getLine() -> char = 0;
public:
    BufferedTextReader(const char *pInputFileName, AbortCode abortCode);

    virtual ~BufferedTextReader() {
        file.close();
        delete pFileName;
    }

    auto character() const -> char {
        return *pChar;
    }

    auto getChar () -> char;
    auto putBackChar() -> char;
};

#endif