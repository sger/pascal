#ifndef ticode_h
#define ticode_h

#include "scanner.h"
#include "token.h"
#include <fstream>

class SymtabNode;

class TICode : public Scanner {
  std::fstream file;
  const char *const pFileName;
  int size;

  char **symtabStrings;
  int symtabCount;

public:
  enum TMode { input, output };

  TICode(const char *pTICodeFileName, TMode mode);
  ~TICode();

  void goTo(int location) { file.seekg(location, std::ios::beg); }

  int sizeOfFile() const { return size; }

  void put(int value);
  void put(Token tc, short index = -1);
  void put(const SymtabNode *pNode);

  virtual Token *get();
  int getInteger();
  void getSymtabStrings();
};

#endif
