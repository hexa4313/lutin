#ifndef EXPMULT_H
#define EXPMULT_H

#include "../symboltype.h"
#include "expression.h"
#include "binaryexp.h"

class ExpMult : public BinaryExp {
  public:
    ExpMult() : BinaryExp(), m_type(SymbolType::MUL) {}
    ExpMult(Expression l, Expression r) : BinaryExp(l, r), m_type(SymbolType::MUL) {}
};

#endif
