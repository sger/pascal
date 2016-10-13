#ifndef scanner_h
#define scanner_h

#include "token.h"
#include "common.h"
#include "word_token.h"

class Scanner {
protected:
	WordToken wordToken;

public:
	virtual ~Scanner() {}
	virtual Token *get() = 0;
};

#endif