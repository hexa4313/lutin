#ifndef BINARYEXP_H
#define BINARYEXP_H

#include "expression.h"

class BinaryExp : public Expression {
  private:
    Expression m_left;
    Expression m_right;
  public:
    BinaryExp() : Expression() {}
    BinaryExp(Expression l, Expression r) : Expression(), m_left(l), m_right(r) {}
    void setLeftExpression(Expression l) : m_left(l) {}
    void setRightExpression(Expression r) : m_right(r) {}
    std::vector<std::shared_ptr<Variable>> getAllVar();
};

#endif
