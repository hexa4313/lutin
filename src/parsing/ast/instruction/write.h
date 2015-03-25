#ifndef WRITE_H
#define WRITE_H

#include <memory>
#include <string>
#include "instruction.h"

class Write : public Instruction {
  private:
    std::shared_ptr<Expression> m_exp;
  public:
    Write() : Instruction(SymbolType::I_W) {}
    Write(std::shared_ptr<Expression> exp) : Instruction(SymbolType::I_W), m_exp(exp) {}
    void toString(std::ostream &o) const;
    std::shared_ptr<Expression> getWrExpr() { return m_exp; }
};

#endif
