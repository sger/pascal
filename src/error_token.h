#ifndef error_token_h
#define error_token_h

#include "token.h"
#include "text_in_buffer.h"

class ErrorToken : public Token {
public:
	ErrorToken() {
		tokenCode = tcError;
	}
	virtual void getToken(TextInBuffer &buffer);
	virtual void print() const {}
	virtual int isDelimiter() const {
		return false;
	}
};

#endif