#ifndef number_token_h
#define number_token_h

#include "token.h"
#include "text_in_buffer.h"

class NumberToken : public Token {
public:
	virtual void get(TextInBuffer &buffer);
	virtual void print() const;
};

#endif