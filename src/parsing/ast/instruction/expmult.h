#ifndef EXPMULT_H
#define EXPMULT_H

#include "../symboltype.h"
#include "binaryexp.h"

class ExpMult : public BinaryExp {
  public:
    ExpMult() : BinaryExp(SymbolType::OP_M) {}
    ExpMult(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) : BinaryExp(SymbolType::OP_M, l, r) {}
    void toString(std::ostream &o) const;
    virtual double eval() { return m_left->eval() * m_right->eval(); }
};

#endif
