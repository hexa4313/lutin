#ifndef READ_H
#define READ_H

#include <memory>
#include <string>
#include "instruction.h"

class Read : public Instruction {
  private:
    std::string m_id;
  public:
    Read() : Instruction(SymbolType::I_R) {}
    Read(std::string id) : Instruction(SymbolType::I_R), m_id(id) {}
    void toString(std::ostream &o) const;
    int eval(std::shared_ptr<SymbolTable> m_table) const;
    void optimize(std::shared_ptr<Program>) {}

    std::string getId() { return m_id; }
};

#endif
