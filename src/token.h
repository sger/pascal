#ifndef token_h
#define token_h

#include "common.h"
#include "text_in_buffer.h"

extern CharCode charCodeMap[]; 

class Token {
protected:
	TokenCode tokenCode;
	DataType dataType;
	DataValue dataValue;
	char tokenString[maxInputBufferSize];
public:
	Token() {
		tokenCode = tcDummy;
		dataType = dtDummy;
		dataValue.integer = 0;
		tokenString[0] = '\0';
	}

	TokenCode getTokenCode() const {
		return tokenCode;
	}

	DataType type() const {
		return dataType;
	}

	DataValue getDataValue() const {
		return dataValue;
	}

	char *getTokenString() {
		return tokenString;
	}

	virtual void get(TextInBuffer &buffer) = 0;
	virtual void print() const = 0;
};

#endif