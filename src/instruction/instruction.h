#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "../symboltype.h"
#include "expression.h"
#include "../symbol.h"

class Instruction : public Symbol {
  public:
    Instruction() : Symbol(SymbolType::I) {}
};

#endif
