#ifndef parser_h
#define parser_h

#include "text_in_buffer.h"
#include "text_scanner.h"
#include "token.h"
#include "common.h"
#include "compact_list_buffer.h"
#include "symbol_table_node.h"

class Parser {
	TextScanner *const pTextScanner;
	Token *currentToken;
	TokenCode currentTokenCode;
	CompactListBuffer *const pCompactListBuffer;

	void getToken() {
		currentToken = pTextScanner->get();
		currentTokenCode = currentToken->getTokenCode();
	}
public:
	Parser(TextInBuffer *textInBuffer) : pTextScanner(new TextScanner(textInBuffer)), pCompactListBuffer(new CompactListBuffer) {}
	~Parser() {
		delete pTextScanner;
		delete pCompactListBuffer;
	}

	void parse();
};

#endif