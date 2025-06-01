#ifndef SOURCE_BUFFER_H
#define SOURCE_BUFFER_H
#include "BufferedTextReader.h"

class SourceBuffer: public BufferedTextReader {
    protected:
     auto getLine() -> char override;

    public:
    explicit SourceBuffer(const char* pSourceFileName);
};

#endif