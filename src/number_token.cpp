#include "number_token.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "list_buffer.h"

void NumberToken::nextToken(TextInBuffer &buffer) {
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
    if (!sawDotDotFlag && ((ch == 'E') || (ch == 'e')))
    {
        dataType = dtReal;
        *ps++ = ch;
        ch = buffer.getChar();

        if ((ch == '+') || (ch == '-'))
        {
            *ps++ = exponentSign = ch;
            ch = buffer.getChar();
        }

        digitCount = 0;

        if (!accumulateValue(buffer, numValue, errorInvalidExponent))
        {
            return;
        }

        if (exponentSign == '-')
        {
            eValue = -eValue;
        }
    }

    // Tracking many digits
    if (countErrorFlag)
    {
        displayError(errorTooManyDigits);
        return;
    }

    // Calculation of the exponent value
    exponent = int(eValue) - decimalPlaces;
    if ((exponent + wholePlaces < -maxExponent) || (exponent + wholePlaces > maxExponent))
    {
        displayError(errorRealOutOfRange);
        return;
    }

    if (exponent != 0)
    {
        numValue  *= float(pow(10, exponent));
    }

    if (dataType == dtInteger)
    {
        if ((numValue < -maxInteger) || (numValue > maxInteger))
        {
            displayError(errorIntegerOutOfRange);
            return;
        }
        dataValue.integer = int(numValue);
    }
    else
    {
        dataValue.real = numValue;
    }

    *ps = '\0';
    tokenCode = tcNumber;
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
    if (dataType == dtInteger)
    {
        sprintf(list.text, "\t%-18s =%d", ">> integer:", dataValue.integer);
    }
    else
    {
        sprintf(list.text, "\t%-18s =%g", ">> real:", dataValue.real);
    }
    list.putLine();
}