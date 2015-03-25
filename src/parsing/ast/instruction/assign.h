#ifndef ASSIGN_H
#define ASSIGN_H

#include <memory>
#include "../symboltype.h"
#include "instruction.h"
#include "expression.h"

class Assign : public Instruction {
  private:
    std::string m_id;
    std::shared_ptr<Expression> m_expr;
  public:
    Assign() : Instruction(SymbolType::AFF) {}
    Assign(std::string id, std::shared_ptr<Expression> e) : Instruction(SymbolType::AFF), m_id(id), m_expr(e) {}
    void toString(std::ostream &o) const;
    
    std::string getAsVar() { return m_id; }
    std::shared_ptr<Expression> getAsExpr() { return m_expr; }
};

#endif
