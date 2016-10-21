#include <stdlib.h>
#include <iostream>
#include "errors.h"
#include "list_buffer.h"
#include "source_buffer.h"

int errorCount = 0;
int errorArrowFlag = true;
int errorArrowOffset = 8;

static const char* const abortMessages[] = {
	NULL,
    "Invalid command line arguments",
    "Failed to open source file",
    "Failed to open intermediate form file",
    "Failed to open assembly file",
    "Too many syntax errors",
    "Stack overflow",
    "Code segment overflow",
    "Nesting too deep",
    "Runtime error",
    "Unimplemented feature",
};

void abort(AbortCode abortCode)
{
	std::cerr << "Fatal translator error: " << abortMessages[-abortCode] << std::endl;
	exit(abortCode);
}

static const char* const errorMessages[] = {
	    "No error",
    "Unrecognizable input",
    "Too many syntax errors",
    "Unexpected end of file",
    "Invalid number",
    "Invalid fraction",
    "Invalid exponent",
    "Too many digits",
    "Real literal out of range",
    "Integer literal out of range",
    "Missing )",
    "Invalid expression",
    "Invalid assignment statement",
    "Missing identifier",
    "Missing :=",
    "Undefined identifier",
    "Stack overflow",
    "Invalid statement",
    "Unexpected token",
    "Missing ;",
    "Missing ,",
    "Missing DO",
    "Missing UNTIL",
    "Missing THEN",
    "Invalid FOR control variable",
    "Missing OF",
    "Invalid constant",
    "Missing constant",
    "Missing :",
    "Missing END",
    "Missing TO or DOWNTO",
    "Redefined identifier",
    "Missing =",
    "Invalid type",
    "Not a type identifier",
    "Invalid subrange type",
    "Not a constant identifier",
    "Missing ..",
    "Incompatible types",
    "Invalid assignment target",
    "Invalid identifier usage",
    "Incompatible assignment",
    "Min limit greater than max limit",
    "Missing [",
    "Missing ]",
    "Invalid index type",
    "Missing BEGIN",
    "Missing .",
    "Too many subscripts",
    "Invalid field",
    "Nesting too deep",
    "Missing PROGRAM",
    "Already specified in FORWARD",
    "Wrong number of actual parameters",
    "Invalid VAR parameter",
    "Not a record variable",
    "Missing variable",
    "Code segment overflow",
    "Unimplemented feature",
};

void displayError(ErrorCode errorCode)
{
	const int maxSyntaxErrors = 25;

	int errorPosition = errorArrowOffset + inputPosition - 1;

	if (errorArrowFlag)
	{
		sprintf(list.text, "%*s^", errorPosition, " ");
		list.putLine();
	}

	sprintf(list.text, "*** ERROR: %s", errorMessages[errorCode]);
	list.putLine();

	if (++errorCount > maxSyntaxErrors)
	{
		list.putLine("Too many syntax errors. Translation aborted.");
		abort(tooManySyntaxErrors);
	}

}