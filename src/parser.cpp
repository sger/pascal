#include "parser.h"

#include <iostream>
#include "list_buffer.h"
#include "common.h"
#include "errors.h"

void Parser::parse() {
	std::cout << "calling parser" << std::endl;

	list.putLine();
	sprintf(list.text, "%20d source lines.", currentLineNumber);
	list.putLine();
	sprintf(list.text, "%20d syntax errors.", errorCount);
	list.putLine();
}

void Parser::getToken() {

}