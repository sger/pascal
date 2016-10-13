#ifndef text_scanner_h
#define text_scanner_h

#include "scanner.h"
#include "text_in_buffer.h"
#include "token.h"

class TextScanner : public Scanner {
	TextInBuffer *const pTextInBuffer;
public:
	TextScanner(TextInBuffer *textInBuffer);

	virtual ~TextScanner() {
		delete pTextInBuffer;
	}

	virtual Token *get();
};

#endif