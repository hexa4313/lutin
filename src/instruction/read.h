#ifndef READ_H
#define READ_H

#include "../symboltype.h"
#include "variable.h"
#include "instruction.h"

class Read : public Instruction {
  private:
    bool m_is_declared;
    bool m_has_value;
    Variable m_destination;
  public:
    Read() : Instruction(), m_type(SymbolType::I_R) {}
    Read(Variable destination) : Instruction(), m_type(SymbolType::I_R), m_destination(destination) {}
};

#endif
