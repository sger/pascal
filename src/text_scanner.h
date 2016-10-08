#ifndef text_scanner_h
#define text_scanner_h

#include "scanner.h"
#include "text_in_buffer.h"

class TextScanner : public Scanner {
	TextInBuffer *const pTextInBuffer;
public:
	TextScanner(TextInBuffer *textInBuffer);

	virtual ~TextScanner() {
		delete pTextInBuffer;
	}
};

#endif