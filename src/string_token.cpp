#include "string_token.h"

#include <stdio.h>
#include <string.h>

#include "list_buffer.h"

void StringToken::getToken(TextInBuffer &buffer) {
	char ch;
	char *ps = tokenString;

	*ps = '\'';

	ch = buffer.getChar();

	while(ch != eofChar) {
		if (ch ==  '\'')
		{
			ch = buffer.getChar();

			if (ch != '\'') break;
		}
		else if(ch == '\0') 
		{
			ch = ' ';
		}

		*ps++ = ch;
		ch = buffer.getChar();
	}

	if (ch == eofChar) displayError(errorUnexpectedEndOfFile);
	
	*ps++ = '\'';
	*ps = '\0';
}

void StringToken::print() const {
	sprintf(list.text, "\t%-18s %-s", ">> string:", tokenString);
	list.putLine();
}