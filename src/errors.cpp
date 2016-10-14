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