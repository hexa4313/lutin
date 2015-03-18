#ifndef CONSTDEC_H
#define CONSTDEC_H

#include <string>
#include "../symbol.h"

class ConstDec : public Symbol {
  private:
    std::string m_name;
    std::string m_value;
    bool m_assigned;
  public:
    ConstDec(std::string name, std::string value): m_name(name), m_value(value), m_assigned(true);
};

#endif
