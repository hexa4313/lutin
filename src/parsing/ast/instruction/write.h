#ifndef WRITE_H
#define WRITE_H

#include <memory>
#include "instruction.h"
#include "expression.h"

class Write : public Instruction {
  private:
    std::shared_ptr<Expression> m_expr;
  public:
    Write() : Instruction(SymbolType::I_W) {}
    Write(std::shared_ptr<Expression> exp) : Instruction(SymbolType::I_W), m_expr(exp) {}
    void toString(std::ostream &o) const;
    int eval(std::shared_ptr<SymbolTable> m_table) const;

    std::shared_ptr<Expression> getExpr() { return m_expr; }
    void replaceExpr(std::shared_ptr<Expression> e) { m_expr = e; }
};

#endif
