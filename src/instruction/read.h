#ifndef READ_H
#define READ_H

#include "../symboltype.h"
#include "variable.h"
#include "instruction.h"

class Read : public Instruction {
  private:
    bool m_is_declared;
    bool m_has_value;
    std::string m_id;
  public:
    Read() : Instruction(SymbolType::I_R) {}
    Read(std::string id) : Instruction(SymbolType::I_R), m_id(id) {}

    std::shared_ptr<Symbol> getInstSymb() { /*return m_destination;*/ };
};

#endif
