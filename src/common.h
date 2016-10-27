#ifndef common_h
#define common_h

#include "symbol_table.h"

const int FALSE = 0;
const int TRUE = 1;

extern int currentLineNumber;
extern int currentNestingLevel;

extern SymbolTable globalSymbolTable;

enum TokenCode {
	tcDummy, 

	// Special Types
	tcNumber, tcEndOfFile, tcError, tcIdentifier, tcString,

	// Symbols
	tcUpArrow, tcStar, tcLParen, tcRParen, tcMinus, tcPlus,
	tcEqual, tcLBracket, tcRBracket, tcColon, tcSemicolon, tcLt,
	tcGt, tcComma, tcPeriod, tcSlash, tcColonEqual, tcLe, tcGe,
	tcNe, tcDotDot,

	tcDO, tcAND, tcARRAY, tcBEGIN, tcCASE, tcCONST, tcDIV,
	tcDOWNTO, tcELSE, tcEND, tcFILE, tcFOR, tcFUNCTION,
	tcGOTO, tcIF, tcIN, tcLABEL, tcMOD, tcNIL, tcNOT, tcOF, tcOR,
	tcPACKED, tcPROCEDURE, tcPROGRAM, tcRECORD, tcREPEAT, tcSET,
	tcTHEN, tcTO, tcTYPE, tcUNTIL, tcVAR, tcWHILE, tcWITH,
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