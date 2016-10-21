#include "number_token.h"

#include <stdio.h>
#include <string.h>

#include "list_buffer.h"

void NumberToken::getToken(TextInBuffer &buffer) {
    const int maxInteger = 32767;
    const int maxExponent = 37;

    float numValue = 0.0;

    int wholePlaces = 0;
    int decimalPlaces = 0;
    char exponentSign = '+';
    float eValue = 0.0;
    int exponent = 0;
    int sawDotDotFlag = false;

    ch = buffer.Char();
    ps = tokenString;
    digitCount = 0;
    countErrorFlag = false;
    tokenCode = tcError;
    dataType = dtInteger;

    if (!accumulateValue(buffer, numValue, errorInvalidNumber))
    {
        return;
    }

    wholePlaces = digitCount;

    if (ch == '.')
    {
        ch = buffer.getChar();

        if (ch == '.')
        {
            sawDotDotFlag = true;
            buffer.putBackChar();
        }
        else
        {
            dataType = dtReal;
            *ps++ = '.';

            if (!accumulateValue(buffer, numValue, errorInvalidFraction))
            {
                return;
            }

            decimalPlaces = digitCount - wholePlaces;
       }
    }

    // exponent part

}

int NumberToken::accumulateValue(TextInBuffer &buffer, float &value, ErrorCode errorCode) {

    const int maxDigitCount = 20;

    if (charCodeMap[ch] != ccDigit)
    {
        displayError(errorCode);
        return false;
    }

    do {
        *ps++ = ch;

        if (++digitCount <= maxDigitCount)
        {
            value = 10 * value + (ch - '0');
        }
        else
        {
            countErrorFlag = true;
        }

        ch = buffer.getChar();
    } while (charCodeMap[ch] == ccDigit);

    return true;
}

void NumberToken::print() const {
	sprintf(list.text, "\t%-18s =%d", ">> number:", dataValue.integer);
    list.putLine();
}