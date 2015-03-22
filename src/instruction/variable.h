#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "../symboltype.h"
#include "expression.h"
#include "instruction.h"

class Variable : public Expression {
  private:
    std::string m_name;
    int m_value;
  public:
    Variable() : Expression(SymbolType::E_VAL) {}
    Variable(std::string name) : Expression(SymbolType::E_VAL), m_name(name) {}
    Variable(std::string name, int value) : Expression(SymbolType::E_VAL), m_name(name), m_value(value) {}
    virtual double eval() { return m_value; }
    std::string getName() { return m_name; }
};

#endif
