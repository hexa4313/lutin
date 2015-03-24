#ifndef NUMERIC_H
#define NUMERIC_H

#include "expression.h"

class NumericConst : public Expression {
  private:
    int m_value;
  public:
    NumericConst() : Expression(SymbolType::E_CNUM) {}
    NumericConst(int value) : Expression(SymbolType::E_CNUM), m_value(value) {}
    virtual double eval() { return m_value; }

    std::shared_ptr<Variable> getVar();
};

#endif
