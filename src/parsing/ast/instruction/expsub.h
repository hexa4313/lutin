#ifndef EXPSUB_H
#define EXPSUB_H

#include "../symboltype.h"
#include "binaryexp.h"

class ExpSub : public BinaryExp {
  public:
    ExpSub() : BinaryExp(SymbolType::OP_A) {}
    ExpSub(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) : BinaryExp(SymbolType::OP_A, l, r) {}
    void toString(std::ostream &o) const;
    virtual double eval() { return m_left->eval() - m_right->eval(); }
};

#endif
