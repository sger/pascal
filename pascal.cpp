#include <iostream>

#include "errors.h"
#include "source_buffer.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
	   std::cerr << "Usage: list <source file>" << std::endl;
       abort(invalidCommandLineArgs);
    }

    SourceBuffer sourceBuffer(argv[1]);
}
