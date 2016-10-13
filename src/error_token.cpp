#include "error_token.h"

#include <stdio.h>
#include <string.h>

void ErrorToken::get(TextInBuffer &buffer) {
	tokenString[0] = buffer.Char();
	tokenString[1] = '\0';
	buffer.getChar();
}
