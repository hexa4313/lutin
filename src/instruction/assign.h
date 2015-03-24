#ifndef ASSIGN_H
#define ASSIGN_H

#include "../symboltype.h"
#include "instruction.h"

class Assign : public Instruction {
  public:
    Assign() : Instruction(SymbolType::AFF) {}

//    std::shared_ptr<Expression> getInstExpr();
//    std::shared_ptr<Variable> getInstVar();
};

#endif
