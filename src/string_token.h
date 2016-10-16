#ifndef string_token_h
#define string_token_h

#include "token.h"
#include "text_in_buffer.h"

class StringToken : public Token {
public:
	virtual void getToken(TextInBuffer &buffer);
	virtual void print() const;
};

#endif