#ifndef common_h
#define common_h

// #include <string.h>
// #include <ctype.h>

const int FALSE = 0;
const int TRUE = 1;

extern int currentLineNumber;
extern int currentNestingLevel;

enum TokenCode {
	tcDummy,
	tcWord,
	tcNumber,
	tcPeriod,
	tcEndOfFile,
	tcError,
};

enum CharCode {
	ccLetter,
	ccDigit,
	ccSpecial,
	ccQuote,
	ccWhiteSpace,
	ccEndOfFile,
	ccError,
};

enum DataType {
	dtDummy,
	dtInteger,
	dtReal,
	dtCharacter,
	dtString,
};

union DataValue {
	int integer;
	float real;
	char character;
	char *pString;
};


#endif