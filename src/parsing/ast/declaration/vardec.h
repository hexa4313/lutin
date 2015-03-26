#ifndef VARDEC_H
#define VARDEC_H

#include <string>
#include "simpledec.h"

class VarDec : public SimpleDec {
  private:
    std::string m_name;
    int m_value;
    bool m_assigned;
  public:
    VarDec(std::string name): SimpleDec(SymbolType::VAR), m_name(name), m_assigned(false) {};
    VarDec(std::string name, int value): SimpleDec(SymbolType::VAR), m_name(name), m_value(value), m_assigned(true) {};
    void toString(std::ostream &o) const;
    std::string getName() const {return m_name;}
    int getValue() const {return m_value;}
};

#endif
