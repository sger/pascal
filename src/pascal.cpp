#include <iostream>

#include "errors.h"
#include "source_buffer.h"
#include "text_in_buffer.h"
#include "parser.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
	   std::cerr << "Usage: pascal <source file>" << std::endl;
       abort(invalidCommandLineArgs);
    }

    //errorArrowFlag = false;
    //listFlag = false;

    Parser parser(new SourceBuffer(argv[1]));
    parser.parse();
}
