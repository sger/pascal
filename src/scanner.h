#ifndef scanner_h
#define scanner_h

#include "token.h"
#include "common.h"
#include "word_token.h"
#include "number_token.h"
#include "string_token.h"
#include "special_token.h"
#include "eof_token.h"
#include "error_token.h"

class Scanner {
protected:
	WordToken wordToken;
	NumberToken numberToken;
	StringToken stringToken;
	SpecialToken specialToken;
	EOFToken eofToken;
	ErrorToken errorToken;

public:
	virtual ~Scanner() {}
	virtual Token *get() = 0;
};

#endif