#ifndef EXPADD_H
#define EXPADD_H

#include "../symboltype.h"
#include "expression.h"
#include "binaryexp.h"

class ExpAdd : public BinaryExp {
  public:
    ExpAdd() : BinaryExp(), m_type(SymbolType::ADD) {}
    ExpAdd(Expression l, Expression r) : BinaryExp(l, r), m_type(SymbolType::ADD) {}
};

#endif
