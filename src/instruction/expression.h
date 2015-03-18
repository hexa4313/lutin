#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <map>
#include <string>
#include "../symbol.h"
#include "../symboltype.h"
#include "expression.h"

class Expression : public Symbol {
  public:
    Expression() : Symbol(SymbolType::E) {}
    virtual ~Expression() {}
    virtual double eval(const map<string, double> & valeurs) = 0;
};

#endif
