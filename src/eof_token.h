#ifndef eof_token_h
#define eof_token_h

#include "token.h"
#include "text_in_buffer.h"

class EOFToken : public Token {
public:
	EOFToken() {
		tokenCode = tcEndOfFile;
	}
	virtual void nextToken(TextInBuffer &buffer) {}
	virtual void print() const {}
	virtual int isDelimiter() const {
		return false;
	}
};

#endif