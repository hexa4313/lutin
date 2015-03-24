#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "../symboltype.h"
#include "expression.h"
#include "../symbol.h"

class Instruction : public Symbol {
  public:
    Instruction(SymbolType t) : Symbol(t) {}

//    virtual std::shared_ptr<Expression> getInstExpr() = 0;
//    virtual std::shared_ptr<Variable> getInstVar() = 0;
};

#endif
