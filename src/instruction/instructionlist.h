#ifndef INSTRUCTION_LIST_H
#define INSTRUCTION_LIST_H

#include <vector>
#include "../symbol.h"
#include "../symboltype.h"
#include "../program.h"
#include "instruction.h"

class InstructionList : public Symbol {
  private:
  std::vector<std::shared_ptr<Instruction>> m_instructions;
  public:
    InstructionList() : Symbol(SymbolType::IL) {}
    InstructionList(std::vector<Instruction> instructions) : Symbol(SymbolType::IL), m_instructions(instructions) {}
    void staticAnalysis(Program program);
    void addInstruction(std::shared_ptr<Instruction> i) { m_instructions.push_back(i); };
};

#endif
