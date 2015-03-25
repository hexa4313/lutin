#ifndef BINARYEXP_H
#define BINARYEXP_H

#include "expression.h"
#include <memory>

class BinaryExp : public Expression {
  protected:
    std::shared_ptr<Expression> m_left;
    std::shared_ptr<Expression> m_right;
  public:
    BinaryExp(SymbolType t) : Expression(t) {}
    BinaryExp(SymbolType t, std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) :
    Expression(t), m_left(l), m_right(r) {}
    void setExpressions(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) {m_left = l; m_right = r;};
};

#endif
