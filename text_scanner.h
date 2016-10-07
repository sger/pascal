#ifndef text_scanner_h
#define text_scanner_h

#include "scanner.h"

class TextScanner : public Scanner {
	TextInBuffer *const pTextInBuffer;
public:
	TextScanner(TextInBuffer *textInBuffer);
};

#endif