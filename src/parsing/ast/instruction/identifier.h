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

    std::string name() { return m_name; }
    std::vector<std::string> getIdentifiers();
};

#endif
