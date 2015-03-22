#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "../symboltype.h"
#include "expression.h"
#include "../symbol.h"

class Instruction : public Symbol {
  public:
    Instruction(SymbolType t) : Symbol(t) {}

    virtual std::shared_ptr<Symbol> getInstSymb() = 0;
};

#endif
