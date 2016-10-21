#ifndef number_token_h
#define number_token_h

#include "token.h"
#include "text_in_buffer.h"

class NumberToken : public Token {
public:
	NumberToken() {
		tokenCode = tcNumber;
	}
	virtual void getToken(TextInBuffer &buffer);
	virtual void print() const;
	virtual int isDelimiter() const {
		return false;
	}
};

#endif