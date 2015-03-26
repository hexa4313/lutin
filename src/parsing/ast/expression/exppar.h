#ifndef EXPPAR_H
#define EXPPAR_H

#include <memory>
#include "expression.h"
#include "../../../interpretation/symboltable.h"

class ExpPar : public Expression {
  private:
    std::shared_ptr<Expression> m_expr;
  public:
    ExpPar() : Expression(SymbolType::E_PAR) {}
    ExpPar(std::shared_ptr<Expression> expression) : Expression(SymbolType::E_PAR), m_expr(expression) {}
    void toString(std::ostream &o) const;
    int eval(std::shared_ptr<SymbolTable> m_table) const;

    std::vector<std::string> getIdentifiers();
    std::shared_ptr<Expression> optimizeConstants(std::map<std::string, int>);
};

#endif
