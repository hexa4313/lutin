#ifndef VARIABLE_H
#define VARIABLE_H

#include <memory>
#include <string>
#include "expression.h"

class Variable : public Expression {
  private:
    std::string m_name;
    int m_value;
  public:
    Variable() : Expression(SymbolType::E_VAL) {}
    Variable(std::string name) : Expression(SymbolType::E_VAL), m_name(name) {}
    Variable(std::string name, int value) : Expression(SymbolType::E_VAL), m_name(name), m_value(value) {}
    void toString(std::ostream &o) const;
    std::string name() { return m_name; }
    virtual double eval() { return m_value; }
};

#endif
