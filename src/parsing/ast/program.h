#ifndef PROGRAM_H
#define PROGRAM_H

#include <memory>
#include "symboltype.h"
#include "symbol.h"
#include "declaration/declarationlist.h"
#include "instruction/instructionlist.h"

class Program : public Symbol {
  private:
    std::shared_ptr<DeclarationList> m_decList;
    std::shared_ptr<InstructionList> m_instList;
  public:
    Program() : Symbol(SymbolType::P) {}
    Program(std::shared_ptr<DeclarationList> dec, std::shared_ptr<InstructionList> inst) : Symbol(SymbolType::P), m_decList(dec), m_instList(inst) {}
    void toString(std::ostream &o) const;
    std::shared_ptr<DeclarationList> getDecList() {return m_decList;}
    std::shared_ptr<InstructionList> getInstList() {return m_instList;}
};

#endif
