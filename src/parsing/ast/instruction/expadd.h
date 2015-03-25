#ifndef EXPADD_H
#define EXPADD_H

#include "../symboltype.h"
#include "expression.h"
#include "binaryexp.h"

class ExpAdd : public BinaryExp {
  public:
    ExpAdd() : BinaryExp(SymbolType::OP_A) {}
    ExpAdd(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) : BinaryExp(SymbolType::OP_A, l, r) {}
    void toString(std::ostream &o) const;
    virtual double eval() { return m_left->eval() + m_right->eval(); }
};

#endif
