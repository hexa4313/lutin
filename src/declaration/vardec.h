#ifndef VARDEC_H
#define VARDEC_H

#include <string>
#include "../symbol.h"

class VarDec : public Symbol {
  private:
    std::string m_name;
    std::string m_value;
    bool m_assigned;
  public:
    VarDec(std::string name, std::string value): m_name(name), m_value(value), m_assigned(true);
    VarDec(std::string name): m_name(name), m_assigned(false);
};

#endif
