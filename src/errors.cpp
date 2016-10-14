#include <stdlib.h>
#include <iostream>
#include "errors.h"

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