#ifndef INSTRUCTION_LIST_H
#define INSTRUCTION_LIST_H

#include <memory>
#include <vector>
#include "../symbol.h"
#include "instruction.h"

class InstructionList : public Symbol {
  private:
    std::vector<std::shared_ptr<Instruction>> m_instructions;
  public:
    InstructionList() : Symbol(SymbolType::IL) {}
    InstructionList(std::vector<std::shared_ptr<Instruction>> instructions) : Symbol(SymbolType::IL), m_instructions(instructions) {}
    void toString(std::ostream &o) const;
    void addInstruction(std::shared_ptr<Instruction> i) { m_instructions.push_back(i); };
    std::vector<std::shared_ptr<Instruction>> getInsts() { return m_instructions; };

    std::shared_ptr<Instruction> lastAssignation(std::string id, std::shared_ptr<Instruction> instruction);
};

#endif
