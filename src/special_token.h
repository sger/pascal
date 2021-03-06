#ifndef special_token_h
#define special_token_h

#include "token.h"
#include "text_in_buffer.h"

class SpecialToken : public Token {
public:
	virtual void nextToken(TextInBuffer &buffer);
	virtual void print() const;
	virtual int isDelimiter() const {
		return true;
	}
};

#endif