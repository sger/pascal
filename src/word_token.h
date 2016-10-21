#ifndef word_token_h
#define word_token_h

#include "token.h"
#include "text_in_buffer.h"

class WordToken : public Token {
	void checkForReservedWord();
public:
	virtual void getToken(TextInBuffer &buffer);
	virtual void print() const;
	virtual int isDelimiter() const {
		return false;
	}
};

#endif