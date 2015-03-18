#ifndef CONSTDEC_H
#define CONSTDEC_H

#include <string>
#include "../symbol.h"

class ConstDec : public Symbol {
  private:
    std::string m_name;
    std::string m_value;
  public:
    ConstDec(std::string name, std::string value) : Symbol(SymbolType::CST), m_name(name), m_value(value) {};
};

#endif
