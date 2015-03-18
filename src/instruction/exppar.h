#ifndef EXPPAR_H
#define EXPPAR_H

#include "expression.h"

class ExpPar : public Expression {
  private:
    Expression m_expr;
  public:
    ExpPar() : Expression() {}
    ExpPar(Expression expression) : Expression(), m_expr(expression) {}
};

#endif
