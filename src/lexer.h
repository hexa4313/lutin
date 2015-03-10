#ifndef LEXER_H
#define LEXER_H

#include "symbol.h"
#include <string>
#include <memory>

class Lexer {
  
  private:
    std::string m_content;
    std::shared_ptr<Symbol> m_curSymbol;

  public:
    Lexer(std::string path);
    std::shared_ptr<Symbol> getSymbol();
    void next();

};

#endif