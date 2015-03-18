#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Symbol.h"

class Expression : public Symbol {
  public:
    Expression():Symbol(EXPRE) {}
    virtual ~Expression() {}
    virtual double eval(const map<string, double> & valeurs) = 0;
};

#endif
