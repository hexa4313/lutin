#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include "../symbol.h"

class Expression : public Symbol {
  public:
    Expression(SymbolType t) : Symbol(t) {}
    virtual ~Expression() {}
    virtual std::vector<std::string> getIdentifiers() = 0;
};

#endif
