#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "../symbol.h"

class Expression : public Symbol {
  public:
    Expression(SymbolType t) : Symbol(t) {}
    virtual ~Expression() {}
    virtual double eval() = 0;
};

#endif
