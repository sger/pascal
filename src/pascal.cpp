#include <iostream>

#include "errors.h"
#include "source_buffer.h"
#include "text_in_buffer.h"
#include "parser.h"
#include "list_buffer.h"
#include "symbol_table.h"
#include "ticode.h"

int main(int argc, char *argv[])
{
    extern int xrefFlag;

    if ((argc != 2) && (argc != 3))
    {
        std::cerr << "Usage: pascal <source file> [-x]" << std::endl;
        abort(invalidCommandLineArgs);
    }

    xrefFlag = (argc == 3) && (strcmp(argv[2], "-x") == 0);

    Parser *parser = new Parser(new SourceBuffer(argv[1]));
    parser->parse();
    delete parser;

    if (xrefFlag)
    {
        list.putLine();
        list.putLine("***** Cross-Reference *****");
        list.putLine();
        globalSymbolTable.print();
    }
}
