#ifndef EXPMULT_H
#define EXPMULT_H

#include "../symboltype.h"
#include "expression.h"
#include "binaryexp.h"

class ExpMult : public BinaryExp {
  public:
    ExpMult() : BinaryExp(SymbolType::OP_M) {}
    ExpMult(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) : BinaryExp(SymbolType::OP_M, l, r) {}
    virtual double eval() { return m_left->eval() * m_right->eval(); }

    std::vector<std::shared_ptr<Variable>> getAllVar();
};

#endif
