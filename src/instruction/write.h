#ifndef WRITE_H
#define WRITE_H

#include <string>
#include "../symboltype.h"
#include "instruction.h"

class Write : public Instruction {
  private:
    std::string m_buffer;
  public:
    Write() : Instruction(), m_type(SymbolType::I_W) {}
    Write(std::string buffer) : Instruction(), m_type(SymbolType::I_W), m_buffer(buffer) {}
};

#endif
