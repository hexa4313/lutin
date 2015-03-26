#ifndef ASSIGN_H
#define ASSIGN_H

#include <memory>
#include "../../../interpretation/symboltable.h"
#include "../symboltype.h"
#include "instruction.h"
#include "../expression/expression.h"

class Assign : public Instruction {
  private:
    std::string m_id;
    std::shared_ptr<Expression> m_expr;
  public:
    Assign() : Instruction(SymbolType::AFF) {}
    Assign(std::string id, std::shared_ptr<Expression> e) : Instruction(SymbolType::AFF), m_id(id), m_expr(e) {}
    void toString(std::ostream &o) const;
    int eval(std::shared_ptr<SymbolTable> m_table) const;
    
    std::string getId() { return m_id; }
    std::shared_ptr<Expression> getExpr() { return m_expr; }
    void replaceExpr(std::shared_ptr<Expression> e) { m_expr = e; }
};

#endif
