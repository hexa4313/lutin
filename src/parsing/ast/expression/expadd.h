#ifndef EXPADD_H
#define EXPADD_H

#include "../symboltype.h"
#include "binaryexp.h"

class ExpAdd : public BinaryExp {
  public:
    ExpAdd() : BinaryExp(SymbolType::OP_A) {}
    ExpAdd(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) : BinaryExp(SymbolType::OP_A, l, r) {}
    void toString(std::ostream &o) const;

    std::shared_ptr<Expression> optimize(std::shared_ptr<Program>);
    int eval(std::shared_ptr<SymbolTable> m_table) const;
};

#endif
