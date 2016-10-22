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
	{(char *)"if", tcIF},
	{(char *)"in", tcIN},
	{(char *)"of", tcOF},
	{(char *)"or", tcOR},
	{(char *)"to", tcTO},
	{NULL},
};

static ReservedWord rw3[] = {
	{(char *)"and", tcAND},
	{(char *)"div", tcDIV},
	{(char *)"end", tcEND},
	{(char *)"for", tcFOR},
	{(char *)"mod", tcMOD},
	{(char *)"nil", tcNIL},
	{(char *)"not", tcNOT},
	{(char *)"set", tcSET},
	{(char *)"var", tcVAR},
	{NULL},
};

static ReservedWord rw4[] = {
	{(char *)"case", tcCASE},
	{(char *)"else", tcELSE},
	{(char *)"file", tcFILE},
	{(char *)"goto", tcGOTO},
	{(char *)"then", tcTHEN},
	{(char *)"type", tcTYPE},
	{(char *)"with", tcWITH},
	{NULL},
};

static ReservedWord rw5[] = {
	{(char *)"array", tcARRAY},
	{(char *)"begin", tcBEGIN},
	{(char *)"const", tcCONST},
	{(char *)"label", tcLABEL},
	{(char *)"until", tcUNTIL},
	{(char *)"while", tcWHILE},
	{NULL},
};

static ReservedWord rw6[] = {
	{(char *)"downto", tcDOWNTO},
	{(char *)"packed", tcPACKED},
	{(char *)"record", tcRECORD},
	{(char *)"repeat", tcREPEAT},
	{NULL},
};

static ReservedWord rw7[] = {
	{(char *)"program", tcPROGRAM},
	{NULL},
};

static ReservedWord rw8[] = {
	{(char *)"function", tcFUNCTION},
	{NULL},
};

static ReservedWord rw9[] = {
	{(char *)"procedure", tcPROCEDURE},
	{NULL},
};

static ReservedWord *rwTable[] = {
	NULL, NULL, rw2, rw3, rw4, rw5, rw6, rw7, rw8, rw9,
};

void WordToken::nextToken(TextInBuffer &buffer) {
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
	int len = strlen(tokenString);

	ReservedWord *pReservedWord;

	tokenCode = tcIdentifier;

	if (( len >= minReswordLen) && (len <= maxResWordLen)) 
	{
		for (pReservedWord = rwTable[len]; pReservedWord->pString; ++pReservedWord)
		{
			if (strcmp(tokenString, pReservedWord->pString) == 0)
			{
				tokenCode = pReservedWord->tokenCode;
				break;
			}
		}
	}
}

void WordToken::print() const {
	if (tokenCode == tcIdentifier)
	{
		sprintf(list.text, "\t%-18s %-s", ">> identifier:", tokenString);
	} 
	else
	{
		sprintf(list.text, "\t%-18s %-s", ">> reserved word:", tokenString);
	}
    list.putLine();
}