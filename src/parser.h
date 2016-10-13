#ifndef parser_h
#define parser_h

#include "text_in_buffer.h"
#include "text_scanner.h"
#include "token.h"
#include "common.h"

class Parser {
	TextScanner *const pTextScanner;
	Token *currentToken;
	TokenCode currentTokenCode;

	void getToken();
public:
	Parser(TextInBuffer *textInBuffer) : pTextScanner(new TextScanner(textInBuffer)) {}
	~Parser() {
		delete pTextScanner;
	}

	void parse();
};

#endif