#include "word_token.h"

#include <stdio.h>
#include <string.h>
#include "list_buffer.h"
#include "helpers.h"
#include "common.h"

const int minReswordLen = 2;
const int maxResWordLen = 9;

struct ReservedWord {
	char *pString;
	TokenCode tokenCode;
};

// (char*)"do"

static ReservedWord rw2[] = {
	{(char *)"do", tcDO},
};

void WordToken::getToken(TextInBuffer &buffer) {
	extern CharCode charCodeMap[];

	char ch = buffer.Char();
	char *ps = tokenString;

	do {
		*ps++ = ch;
		ch = buffer.getChar();
	} while( (charCodeMap[ch] == ccLetter) || (charCodeMap[ch] == ccDigit) );

	*ps = '\0';
	strlwr(tokenString);

	checkForReservedWord();
}

void WordToken::checkForReservedWord() {

}

void WordToken::print() const {
	sprintf(list.text, "\t%-18s %-s", ">> word:", tokenString);
    list.putLine();
}