#ifndef INSTRUCTION_LIST_H
#define INSTRUCTION_LIST_H

#include <vector>
#include "../symbol.h"
#include "../program.h"
#include "instruction.h"

class InstructionList : public Symbol {
  private:
    std::vector<Instruction> m_instructions;
  public:
    InstructionList();
    InstructionList(std::vector<Instruction> instructions): m_instructions(instructions);
    void staticAnalysis(Program program);
};

#endif
