#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <memory>
#include "ast/symbol.h"

class Lexer {
  
  private:
    int m_line;
    int m_char;
    std::string m_content;
    std::shared_ptr<Symbol> m_curSymbol;

    void trim();

  public:
    Lexer(std::string path);
    std::shared_ptr<Symbol> getSymbol();
    void shift();

};

#endif