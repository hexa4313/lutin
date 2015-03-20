#ifndef EXPPAR_H
#define EXPPAR_H

#include <memory>
#include "expression.h"

class ExpPar : public Expression {
  private:
  std::shared_ptr<Expression> m_expr;
  public:
    ExpPar() : Expression(SymbolType::E) {}
    ExpPar(std::shared_ptr<Expression> expression) : Expression(SymbolType::E), m_expr(expression) {}
    std::vector<std::shared_ptr<Variable>> getAllVar() { return m_expr.getAllVar(); }
};

#endif
