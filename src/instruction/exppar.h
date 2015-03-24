#ifndef EXPPAR_H
#define EXPPAR_H

#include <memory>
#include "expression.h"

class ExpPar : public Expression {
  private:
    std::shared_ptr<Expression> m_expr;
  public:
    ExpPar() : Expression(SymbolType::E_PAR) {}
    ExpPar(std::shared_ptr<Expression> expression) : Expression(SymbolType::E_PAR), m_expr(expression) {}
    void toString(std::ostream &o) const;
    virtual double eval() { return m_expr->eval(); }
};

#endif
