#ifndef WRITE_H
#define WRITE_H

#include <string>
#include "../symboltype.h"
#include "instruction.h"

class Write : public Instruction {
  private:
    Expression m_exp;
  public:
    Write() : Instruction(), m_type(SymbolType::I_W) {}
    Write(Expression exp) : Instruction(), m_type(SymbolType::I_W), m_exp(exp) {}
    //void eval() {m_exp.eval()};
};

#endif
