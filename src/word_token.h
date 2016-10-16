#ifndef word_token_h
#define word_token_h

#include "token.h"
#include "text_in_buffer.h"

class WordToken : public Token {
public:
	virtual void getToken(TextInBuffer &buffer);
	virtual void print() const;
};

#endif