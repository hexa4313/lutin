#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "../symbol.h"

class Instruction : public Symbol {
  public:
    Instruction(SymbolType t) : Symbol(t) {}
};

#endif
