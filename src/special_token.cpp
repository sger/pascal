#include "special_token.h"

#include "list_buffer.h"
#include <stdio.h>
#include <string.h>

// refactor this to nextToken
void SpecialToken::nextToken(TextInBuffer &buffer) {
  char ch = buffer.Char();
  char *ps = tokenString;

  *ps++ = ch;

  switch (ch) {
  case '^':
    tokenCode = tcUpArrow;
    buffer.getChar();
    break;
  case '*':
    tokenCode = tcStar;
    buffer.getChar();
    break;
  case '(':
    tokenCode = tcLParen;
    buffer.getChar();
    break;
  case ')':
    tokenCode = tcRParen;
    buffer.getChar();
    break;
  case '-':
    tokenCode = tcMinus;
    buffer.getChar();
    break;
  case '+':
    tokenCode = tcPlus;
    buffer.getChar();
    break;
  case '=':
    tokenCode = tcEqual;
    buffer.getChar();
    break;
  case '[':
    tokenCode = tcLBracket;
    buffer.getChar();
    break;
  case ']':
    tokenCode = tcRBracket;
    buffer.getChar();
    break;
  case ';':
    tokenCode = tcSemicolon;
    buffer.getChar();
    break;
  case ',':
    tokenCode = tcComma;
    buffer.getChar();
    break;
  case '/':
    tokenCode = tcSlash;
    buffer.getChar();
    break;
  case ':':
    ch = buffer.getChar();
    if (ch == '=') {
      *ps++ = '=';
      tokenCode = tcColonEqual;
      buffer.getChar();
    } else {
      tokenCode = tcColon;
    }
    break;
  case '<':
    ch = buffer.getChar();
    if (ch == '=') {
      *ps++ = '=';
      tokenCode = tcLe;
      buffer.getChar();
    } else if (ch == '>') {
      *ps++ = '>';
      tokenCode = tcNe;
      buffer.getChar();
    } else {
      tokenCode = tcLt;
    }
    break;
  case '>':
    ch = buffer.getChar();
    if (ch == '=') {
      *ps++ = '=';
      tokenCode = tcGe;
      buffer.getChar();
    } else {
      tokenCode = tcGt;
    }
    break;
  case '.':
    ch = buffer.getChar();
    if (ch == '.') {
      *ps++ = '.';
      tokenCode = tcDotDot;
      buffer.getChar();
    } else {
      tokenCode = tcPeriod;
    }
    break;
  default:
    tokenCode = tcError;
    buffer.getChar();
    displayError(errorUnrecognizable);
    break;
  }

  *ps = '\0';
}

void SpecialToken::print() const {
  sprintf(list.text, "\t%-18s %-s", ">> special:", tokenString);
  list.putLine();
}