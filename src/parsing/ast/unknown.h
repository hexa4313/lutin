#ifndef _UNKNOWN_H
#define _UNKNOWN_H

#include <string>
#include "symbol.h"

class Unknown : public Symbol {
  private:
    std::string m_value;
  public:
    Unknown(std::string value): Symbol(SymbolType::UNKNOWN), m_value(value) {};
    std::string getValue() const {return m_value;};
};


#endif
