#ifndef VARIABLE_H
#define VARIABLE_H

#include <memory>
#include <string>
#include "expression.h"

class Identifier : public Expression {
  private:
    std::string m_name;
  public:
    Identifier() : Expression(SymbolType::E_VAL) {}
    Identifier(std::string name) : Expression(SymbolType::E_VAL), m_name(name) {}
    void toString(std::ostream &o) const;
    int eval(std::shared_ptr<SymbolTable> m_table) const;

    std::string name() { return m_name; }
    std::vector<std::string> getIdentifiers();
    std::shared_ptr<Expression> optimize(std::shared_ptr<Program>, std::shared_ptr<Instruction>);
};

#endif
