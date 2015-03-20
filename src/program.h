#ifndef PROGRAM_H
#define PROGRAM_H

#include "symboltype.h"
#include "symbol.h"
#include "declaration/declarationlist.h"
#include "instruction/instructionlist.h"

class InstructionList;

class Program : public Symbol {
  private:
    std::shared_ptr<DeclarationList> m_decList;
    std::shared_ptr<InstructionList> m_instList;
  public:
    Program() : Symbol(SymbolType::P) {}
    Program(std::shared_ptr<DeclarationList> dec, std::shared_ptr<InstructionList> inst) : Symbol(SymbolType::P), m_decList(dec), m_instList(inst) {}
    //checkVarDec();
    bool StaticAnalysis(void);
    std::shared_ptr<DeclarationList> getDecList() {return m_decList;}
};

#endif
