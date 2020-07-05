#include "parser.h"

#include "common.h"
#include "errors.h"
#include "list_buffer.h"
#include <iostream>

// Parser symbol table
void Parser::parse() {
  do {
    getToken();

    if (currentTokenCode == tcEndOfFile) {
      displayError(errorUnexpectedEndOfFile);
      break;
    }

    if (currentTokenCode == tcIdentifier) {
      SymbolTableNode *pNode =
          globalSymbolTable.search(currentToken->getTokenString());

      if (!pNode) {
        pNode = globalSymbolTable.enter(currentToken->getTokenString());
      }
    }

  } while (currentTokenCode != tcPeriod);

  list.putLine();
  sprintf(list.text, "%20d source lines.", currentLineNumber);
  list.putLine();
  sprintf(list.text, "%20d syntax errors.", errorCount);
  list.putLine();
}

/*void Parser::parse() {
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
}*/

// Compact representation of the code
// Uncomment this parse function to enable it.
/*void Parser::parse() {

        int currrentTokenIsDelimiter;
        int previousTokenIsDelimiter = true;

        do {
                getToken();

                if (currentTokenCode == tcEndOfFile)
                {
                        displayError(errorUnexpectedEndOfFile);
                        break;
                }

                if (currentTokenCode != tcError) {
                        currrentTokenIsDelimiter = currentToken->isDelimiter();

                        if (!previousTokenIsDelimiter &&
!currrentTokenIsDelimiter)
                        {
                                pCompactListBuffer->putBlank();
                        }

                        pCompactListBuffer->put(currentToken->getTokenString());
                } else {
                        displayError(errorUnrecognizable);
                }

        } while (currentTokenCode != tcPeriod);

        pCompactListBuffer->putLine();
}*/