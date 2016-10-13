#include "parser.h"

#include <iostream>
#include "list_buffer.h"
#include "common.h"
#include "errors.h"

void Parser::parse() {
	std::cout << "starting parser" << std::endl;

	do {
		getToken();

		if (currentTokenCode != Error)
		{
			currentToken->print();
		} else {
			sprintf(list.text, "\t%-18s %-s", ">> *** ERROR ***", currentToken->getTokenString());
			list.putLine();
			++errorCount;
		}
	} while (currentTokenCode != EndOfFile);

	list.putLine();
	sprintf(list.text, "%20d source lines.", currentLineNumber);
	list.putLine();
	sprintf(list.text, "%20d syntax errors.", errorCount);
	list.putLine();
}

void Parser::getToken() {
	currentToken = pTextScanner->get();
	currentTokenCode = currentToken->code();
}