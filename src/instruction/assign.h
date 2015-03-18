#ifndef ASSIGN_H
#define ASSIGN_H

#include "../symboltype.h"
#include "instruction.h"

class Assign : public Instruction {
  public:
    Assign() : Instruction(), m_type(SymbolType::AFF) {}
};

#endif
