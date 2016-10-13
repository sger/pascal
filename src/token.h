#ifndef token_h
#define token_h

#include "common.h"
#include "text_in_buffer.h"

class Token {
protected:
	TokenCode tokenCode;
	char tokenString[maxInputBufferSize];
public:
	Token() {
		tokenCode = tcDummy;
		tokenString[0] = '\0';
	}

	TokenCode code() const {
		return tokenCode;
	}

	char *getTokenString() {
		return tokenString;
	}

	virtual void get(TextInBuffer &buffer) = 0;
	virtual void print() const = 0;
};

#endif