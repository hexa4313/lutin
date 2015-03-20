#ifndef DECLARATION_H
#define DECLARATION_H

#include "../symbol.h"

class Declaration : public Symbol {
  public:
    Declaration(SymbolType symbolType) : Symbol(symbolType) {};
    virtual std::vector<std::shared_ptr<Symbol>> getDecList() = 0;
};

#endif
