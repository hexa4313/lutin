#ifndef EXPMULT_H
#define EXPMULT_H

#include "../symboltype.h"
#include "binaryexp.h"

class ExpMult : public BinaryExp {
  public:
    ExpMult() : BinaryExp(SymbolType::OP_M) {}
    ExpMult(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) : BinaryExp(SymbolType::OP_M, l, r) {}
    void toString(std::ostream &o) const;

    std::shared_ptr<Expression> optimize(std::shared_ptr<Program>, std::shared_ptr<Instruction>);
    int eval(std::shared_ptr<SymbolTable> m_table) const;
};

#endif
