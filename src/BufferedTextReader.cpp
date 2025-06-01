#include "BufferedTextReader.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <ctime>

BufferedTextReader::BufferedTextReader(const char *pInputFileName, AbortCode abortCode)
    : pFileName(new char[strlen(pInputFileName) + 1]) {
    strcpy(pFileName, pInputFileName);

    file.open(pFileName, std::ios::in);
    if (!file.good()) {
    }
}