#ifndef EXPMULT_H
#define EXPMULT_H

#include "../symboltype.h"
#include "expression.h"
#include "binaryexp.h"

class ExpMult : public BinaryExp {
  public:
    ExpMult() : BinaryExp(), m_type(SymbolType::OP_M) {}
    ExpMult(Expression l, Expression r) : BinaryExp(l, r), m_type(SymbolType::OP_M) {}
};

#endif
