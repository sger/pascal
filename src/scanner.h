#ifndef scanner_h
#define scanner_h

#include "token.h"
#include "common.h"

class Scanner {
protected:

public:
	virtual ~Scanner() {}
	virtual Token *get() = 0;
};

#endif