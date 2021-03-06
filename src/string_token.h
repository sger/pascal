#ifndef string_token_h
#define string_token_h

#include "token.h"
#include "text_in_buffer.h"

class StringToken : public Token {
public:
	virtual void nextToken(TextInBuffer &buffer);
	virtual void print() const;
	virtual int isDelimiter() const {
		return true;
	}
};

#endif