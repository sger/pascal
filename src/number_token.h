#ifndef number_token_h
#define number_token_h

#include "token.h"
#include "text_in_buffer.h"

class NumberToken : public Token {
	char ch;
	char *ps;
	int digitCount;
	int countErrorFlag;

	int accumulateValue(TextInBuffer &buffer, float &value, ErrorCode errorCode);
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