#ifndef EXPDIV_H
#define EXPDIV_H

#include "../symboltype.h"
#include "expression.h"
#include "binaryexp.h"

class ExpDiv : public BinaryExp {
  public:
    ExpDiv() : BinaryExp(), m_type(SymbolType::OP_M) {}
    ExpDiv(Expression l, Expression r) : BinaryExp(l, r), m_type(SymbolType::DIV) {}
};

#endif
