#ifndef ASSIGN_H
#define ASSIGN_H

#include <memory>
#include "../symboltype.h"
#include "instruction.h"

class Assign : public Instruction {
  private:
    std::shared_ptr<Variable> m_destination;
    std::shared_ptr<Expression> m_expr;
  public:
    Assign() : Instruction(SymbolType::AFF) {}
    Assign(std::shared_ptr<Variable> d, std::shared_ptr<Expression> e) : Instruction(SymbolType::AFF), m_destination(d), m_expr(e) {}

    std::shared_ptr<Symbol> getInstSymb() { return m_destination; }
};

#endif
