#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include "../symbol.h"

class Expression : public Symbol {
  public:
    Expression(SymbolType t) : Symbol(t) {}
    virtual ~Expression() {}
    virtual double eval() = 0;
    virtual std::vector<std::string> getVariables() = 0;
};

#endif
