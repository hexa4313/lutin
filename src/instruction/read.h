#ifndef READ_H
#define READ_H

#include "../symboltype.h"
#include "variable.h"
#include "instruction.h"

class Read : public Instruction {
  private:
    bool m_is_declared;
    bool m_has_value;
    std::shared_ptr<Variable> m_destination;
  public:
    Read() : Instruction(SymbolType::I_R) {}
    Read(std::shared_ptr<Variable> destination) : Instruction(SymbolType::I_R), m_destination(destination) {}

    std::shared_ptr<Symbol> getInstSymb() { return m_destination; };
};

#endif
