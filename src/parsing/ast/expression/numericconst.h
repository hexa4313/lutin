#ifndef NUMERIC_H
#define NUMERIC_H

#include <memory>
#include "expression.h"

class NumericConst : public Expression {
  private:
    int m_value;
  public:
    NumericConst() : Expression(SymbolType::E_CNUM) {}
    NumericConst(int value) : Expression(SymbolType::E_CNUM), m_value(value) {}
    void toString(std::ostream &o) const;
    int eval(std::shared_ptr<SymbolTable> m_table) const;

    int getValue() { return m_value; };
    std::vector<std::string> getIdentifiers();
    std::shared_ptr<Expression> optimize(std::shared_ptr<DeclarationList>);
};

#endif
