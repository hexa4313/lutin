#ifndef PROGRAM_H
#define PROGRAM_H

#include "symboltype.h"
#include "symbol.h"
#include "declaration/declarationlist.h"
#include "instruction/instructionlist.h"

class Program : public Symbol {
  private:
    DeclarationList m_decList;
    InstructionList m_instList;
  public:
    Program() : Symbol(SymbolType::P) {}
    Program(DeclarationList dec, InstructionList inst) : Symbol(SymbolType::P), m_decList(dec), m_instList(inst) {}
    checkVarDec();
};

#endif
