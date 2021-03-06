#ifndef CONSTDEC_H
#define CONSTDEC_H

#include <string>
#include "simpledec.h"

class ConstDec : public SimpleDec {
  private:
    std::string m_name;
    int m_value;
  public:
    ConstDec(std::string name, int value) : SimpleDec(SymbolType::CST), m_name(name), m_value(value) {};
    void toString(std::ostream &o) const;
    std::string getName() const {return m_name;}
    int getValue() const {return m_value;}
};

#endif
