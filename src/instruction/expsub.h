#ifndef EXPSUB_H
#define EXPSUB_H

#include "../symboltype.h"
#include "expression.h"
#include "binaryexp.h"

class ExpSub : public BinaryExp {
  public:
    ExpSub() : BinaryExp(), m_type(SymbolType::SUB) {}
    ExpSub(Expression l, Expression r) : BinaryExp(l, r), m_type(SymbolType::SUB) {}
};

#endif
