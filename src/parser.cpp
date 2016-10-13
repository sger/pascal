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
		} else {
			sprintf(list.text, "\t%-18s %-s", ">> *** ERROR ***", currentToken->getTokenString());
			list.putLine();
			++errorCount;
		}
	} while (currentTokenCode != tcEndOfFile);

	list.putLine();
	sprintf(list.text, "%20d source lines.", currentLineNumber);
	list.putLine();
	sprintf(list.text, "%20d syntax errors.", errorCount);
	list.putLine();
}