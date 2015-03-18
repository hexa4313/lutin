#ifndef DECLARATION_H
#define DECLARATION_H

#include "../symbol.h"

class Declaration : public Symbol {
  public:
    Declaration(SymbolType symbolType) : Symbol(symbolType) {};
};

#endif
