#include <stdlib.h>
#include <iostream>
#include "errors.h"

static const char* const messages[] = {
	NULL,
    "Invalid command line arguments",
    "Failed to open source file",
};

void abort(ErrorCode errorCode)
{
	std::cerr << "Fatal translator error: " << messages[-errorCode] << std::endl;
	exit(errorCode);
}