#ifndef CONSTDEC_H
#define CONSTDEC_H

#include <string>
#include "../symbol.h"

class ConstDec : public Symbol {
  private:
    std::string m_name;
    int m_value;
  public:
    ConstDec(std::string name, int value) : Symbol(SymbolType::CST), m_name(name), m_value(value) {};
};

#endif
