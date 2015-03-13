#ifndef INSTRUCTIONLIST_H
#define INSTRUCTIONLIST_H

#include "instruction.h"
#include <list>

class InstructionList {

  protected:
    std::list<Instruction> listInstruction;

  public:
    Instructionlist (std::list<Instruction> listInstruction);
};

#endif
