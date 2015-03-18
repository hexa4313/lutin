#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "../symboltype.h"
#include "expression.h"

class Variable : public Expression {
  private:
    std::string m_name;
    std::string m_value;
  public:
    Variable() : Instruction(), m_type(SymbolType::V) {}
    Variable(std::string name) : Instruction(), m_type(SymbolType::V), m_name(name) {}
    Variable(std::string name, std::string value) : Instruction(), m_type(SymbolType::V), m_name(name), m_value(value) {}
};

#endif
