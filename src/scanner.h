#ifndef scanner_h
#define scanner_h

#include "token.h"
#include "common.h"
#include "word_token.h"
#include "number_token.h"

class Scanner {
protected:
	WordToken wordToken;
	NumberToken numberToken;

public:
	virtual ~Scanner() {}
	virtual Token *get() = 0;
};

#endif