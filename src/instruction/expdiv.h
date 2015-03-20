#ifndef EXPDIV_H
#define EXPDIV_H

#include "../symboltype.h"
#include "expression.h"
#include "binaryexp.h"

class ExpDiv : public BinaryExp {
  public:
    ExpDiv() : BinaryExp(SymbolType::OP_M) {}
    ExpDiv(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) : BinaryExp(SymbolType::OP_M, l, r) {}
    virtual double eval() { return m_left->eval() / m_right->eval(); }
};

#endif
