#ifndef WRITE_H
#define WRITE_H

#include <string>
#include "../symboltype.h"
#include "instruction.h"

class Write : public Instruction {
  private:
    std::shared_ptr<Expression> m_exp;
  public:
    Write() : Instruction(SymbolType::I_W) {}
    Write(std::shared_ptr<Expression> exp) : Instruction(SymbolType::I_W), m_exp(exp) {}

    std::shared_ptr<Expression> getWrExpr() { return m_exp; }
//    std::shared_ptr<Variable> getInstVar();
};

#endif
