#ifndef BINARYEXP_H
#define BINARYEXP_H

#include <memory>
#include <vector>

#include "expression.h"
#include "identifier.h"

class BinaryExp : public Expression {
  protected:
    std::shared_ptr<Expression> m_left;
    std::shared_ptr<Expression> m_right;
  public:
    BinaryExp(SymbolType t) : Expression(t) {}
    BinaryExp(SymbolType t, std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) :
    Expression(t), m_left(l), m_right(r) {}
    void setExpressions(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) {m_left = l; m_right = r;};

    std::vector<std::string> getIdentifiers();
};

#endif
