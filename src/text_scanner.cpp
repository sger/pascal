#include "text_scanner.h"

#include <iostream>

TextScanner::TextScanner(TextInBuffer *textInBuffer) : pTextInBuffer(textInBuffer) {

}

void TextScanner::skipWhiteSpace() {
	std::cout << "skipWhiteSpace()" << std::endl;
}

Token *TextScanner::get() {
	std::cout << "get()" << std::endl;
}