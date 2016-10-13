#include "word_token.h"

#include <stdio.h>
#include <string.h>
#include "list_buffer.h"
#include "helpers.h"

void WordToken::get(TextInBuffer &buffer) {
	char ch = buffer.Char();
	char *ps = tokenString;

	do {
		*ps++ = ch;
		ch = buffer.getChar();
	} while( (charCodeMap[ch] == ccLetter) || (charCodeMap[ch] == ccDigit));

	*ps = '\0';
	strlwr(tokenString);
	tokenCode = tcWord;
}

void WordToken::print() const {
	sprintf(list.text, "\t%-18s %-s", ">> word:", tokenString);
    list.putLine();
}