#include <iostream>

#include "errors.h"
#include "source_buffer.h"

int main(int argc, char *argv[])
{
    char ch;

    if (argc != 2) {
	   std::cerr << "Usage: pascal <source file>" << std::endl;
       abort(invalidCommandLineArgs);
    }

    SourceBuffer sourceBuffer(argv[1]);

    do {
        ch = sourceBuffer.getChar();
    } while (ch != eofChar);
}
