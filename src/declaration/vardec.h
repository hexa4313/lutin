#ifndef VARDEC_H
#define VARDEC_H

#include <string>
#include "../symbol.h"

class VarDec : public Symbol {
  private:
    std::string m_name;
    int m_value;
    bool m_assigned;
  public:
    VarDec(std::string name): Symbol(SymbolType::VAR), m_name(name), m_assigned(false) {};
    VarDec(std::string name, int value): Symbol(SymbolType::VAR), m_name(name), m_value(value), m_assigned(true) {};
    std::string getName() const {return m_name;}
    int getValue() const {return m_value;}
};

#endif
