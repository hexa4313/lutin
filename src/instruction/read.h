#ifndef READ_H
#define READ_H

#include <memory>
#include <string>
#include "instruction.h"

class Read : public Instruction {
  private:
    bool m_is_declared;
    bool m_has_value;
    std::string m_id;
  public:
    Read() : Instruction(SymbolType::I_R) {}
    Read(std::string id) : Instruction(SymbolType::I_R), m_id(id) {}
    void toString(std::ostream &o) const;
    std::shared_ptr<Variable> getRdVar() { return m_destination; }
};

#endif
