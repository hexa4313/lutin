#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "../symbol.h"
#include "../../../interpretation/symboltable.h"

class Instruction : public Symbol {
  public:
    Instruction(SymbolType t) : Symbol(t) {}
    virtual int eval(std::shared_ptr<SymbolTable> m_table) const = 0;
};

#endif
