#ifndef BUFFERED_TEXT_READER_H
#define BUFFERED_TEXT_READER_H

#include <stdio.h>
#include <string.h>
#include <fstream>
#include "AbortCode.h"
#include <array>

constexpr int maxInputBufferSize = 256;

class BufferedTextReader {
protected:
    std::fstream file;
    std::string pFileName;
    std::array<char, maxInputBufferSize> text{};
    char *pChar = nullptr;

    virtual auto getLine() -> char = 0;
public:
    BufferedTextReader(const char *pInputFileName, AbortCode abortCode);
    virtual ~BufferedTextReader();

    auto character() const -> char {
        return *pChar;
    }

    auto getChar () -> char;
    auto putBackChar() -> char;
};

#endif