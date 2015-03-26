#ifndef DECLARATION_H
#define DECLARATION_H

#include "../symbol.h"
#include "simpledec.h"

class Declaration : public Symbol {
  public:
    Declaration(SymbolType symbolType) : Symbol(symbolType) {};
    virtual std::vector<std::shared_ptr<SimpleDec>> getDecList() const = 0;
};

#endif
