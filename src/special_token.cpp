#include "special_token.h"

#include <stdio.h>
#include <string.h>
#include "list_buffer.h"

void SpecialToken::getToken(TextInBuffer &buffer) {
	char  ch = buffer.Char();
    char *ps = tokenString;

    *ps++ = ch;
    *ps = '\0';
    buffer.getChar();

    tokenCode = (ch == '.') ? tcPeriod : tcError;
}

void SpecialToken::print() const {
	sprintf(list.text, "\t%-18s %-s", ">> special:", tokenString);
    list.putLine();
}