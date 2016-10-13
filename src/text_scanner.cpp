#include "text_scanner.h"

#include <iostream>

#include "errors.h"
#include "source_buffer.h"
#include "text_in_buffer.h"
#include "parser.h"

CharCode charCodeMap[128];

TextScanner::TextScanner(TextInBuffer *textInBuffer) : pTextInBuffer(textInBuffer) {
	int i;

	for(i = 0; i <= 127; i++) {
		charCodeMap[i] = ccError;
	}

	for (int i = 'a'; i < 'z'; i++) {
		charCodeMap[i] = ccLetter;
	}

	for (int i = 'A'; i < 'Z'; i++) {
		charCodeMap[i] = ccLetter;
	}

	for (int i = '0'; i < '9'; i++) {
		charCodeMap[i] = ccDigit;
	}
    // cast (unsigned char)
	charCodeMap['+'] = ccSpecial;
	charCodeMap['-'] = ccSpecial;
	charCodeMap['*'] = ccSpecial;
	charCodeMap['/'] = ccSpecial;
	charCodeMap['='] = ccSpecial;
	charCodeMap['^'] = ccSpecial;
	charCodeMap['.'] = ccSpecial;
	charCodeMap[','] = ccSpecial;
	charCodeMap['<'] = ccSpecial;
	charCodeMap['>'] = ccSpecial;
	charCodeMap['('] = ccSpecial;
	charCodeMap[')'] = ccSpecial;
	charCodeMap['['] = ccSpecial;
	charCodeMap[']'] = ccSpecial;
	charCodeMap['{'] = ccSpecial;
	charCodeMap['}'] = ccSpecial;
	charCodeMap[':'] = ccSpecial;
	charCodeMap[';'] = ccSpecial;
	charCodeMap[' '] = ccWhiteSpace;
	charCodeMap['\t'] = ccWhiteSpace;
	charCodeMap['\n'] = ccWhiteSpace;
	charCodeMap['\0'] = ccWhiteSpace;
	charCodeMap['\''] = ccQuote;
	charCodeMap[eofChar] = ccEndOfFile;
}

void TextScanner::skipWhiteSpace() {
	std::cout << "skipWhiteSpace()" << std::endl;
}

Token *TextScanner::get() {
	std::cout << "get()" << std::endl;

	Token *currentToken = NULL;

	skipWhiteSpace();

	switch(charCodeMap[pTextInBuffer->Char()]) {
		case ccLetter:
			currentToken = &wordToken;
			break;
		case ccDigit:
			currentToken = &numberToken;
			break;
		case ccQuote:
			break;
		case ccSpecial:
			break;
		case ccEndOfFile:
			break;
		default:
			break;
	}

	currentToken->get(*pTextInBuffer);
	return currentToken;
}