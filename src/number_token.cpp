#include "number_token.h"

#include <stdio.h>
#include <string.h>

#include "list_buffer.h"

void NumberToken::getToken(TextInBuffer &buffer) {
	const int maxDigitCount = 4;
    
    char  ch = buffer.Char();      // char fetched from input
    char *ps = tokenString;
    int   digitCount     = 0;
    int   countErrorFlag = false;  // true if too many digits,
				   //   else false

    //--Accumulate the dataValue as long as the total allowable
    //--number of digits has not been exceeded.
    dataValue.integer = 0;
    do {
	*ps++ = ch;

	//--Shift left and add.
	if (++digitCount <= maxDigitCount) {
	    dataValue.integer = 10*dataValue.integer + (ch - '0');
	}
	else countErrorFlag = true;  // too many digits

	ch = buffer.getChar();
    } while (charCodeMap[ch] == ccDigit);

    *ps  = '\0';
    tokenCode = countErrorFlag ? tcError : tcNumber;
}

void NumberToken::print() const {
	sprintf(list.text, "\t%-18s =%d", ">> number:", dataValue.integer);
    list.putLine();
}