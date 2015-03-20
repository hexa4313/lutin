#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <map>
#include <string>
#include "../symbol.h"
#include "../symboltype.h"
#include "expression.h"

class Variable;

class Expression : public Symbol {
  public:
    Expression(SymbolType t) : Symbol(t) {}
    virtual ~Expression() {}
    virtual double eval() = 0;
};

#endif
