#include "parser.h"

#include <iostream>
#include "list_buffer.h"
#include "common.h"
#include "errors.h"

void Parser::parse() {
	do {
		getToken();

		if (currentTokenCode != tcError) {
			currentToken->print();
		}
		
	} while (currentTokenCode != tcEndOfFile);

	list.putLine();
	sprintf(list.text, "%20d source lines.", currentLineNumber);
	list.putLine();
	sprintf(list.text, "%20d syntax errors.", errorCount);
	list.putLine();
}