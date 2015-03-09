#IFNDEF LEXER_H
#DEFINE LEXER_H

#include "symbol.h"
#include <string>

class Lexer {
  
  private:
    std::string content;

  public:
    Lexer(std::string path);
    Symbol getSymbol();
    void next();

};

#ENDIF