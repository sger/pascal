#include "compact_list_buffer.h"

#include <iostream>

void CompactListBuffer::putBlank() {
  if (++textLength >= maxCompactTextLength - 1) {
    putLine();
  } else {
    *pText++ = ' ';
  }
}

void CompactListBuffer::put(const char *pString) {
  int tokenLength = strlen(pString);

  if (textLength + tokenLength >= maxCompactTextLength - 1) {
    putLine();
  }

  strcpy(pText, pString);
  pText += tokenLength;
  textLength += tokenLength;
}

void CompactListBuffer::putLine() {
  if (textLength > 0) {
    *pText = '\0';
    std::cout << text << std::endl;
    pText = text;
    textLength = 0;
  }
}