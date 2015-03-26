#ifndef EXPDIV_H
#define EXPDIV_H

#include "../symboltype.h"
#include "binaryexp.h"

class ExpDiv : public BinaryExp {
  public:
    ExpDiv() : BinaryExp(SymbolType::OP_M) {}
    ExpDiv(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) : BinaryExp(SymbolType::OP_M, l, r) {}
    void toString(std::ostream &o) const;

    std::shared_ptr<Expression> optimize(std::shared_ptr<Program>);
    int eval(std::shared_ptr<SymbolTable> m_table) const;
};

#endif
