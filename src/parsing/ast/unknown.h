#ifndef _UNKNOWN_H
#define _UNKNOWN_H

#include <string>
#include "symbol.h"

class Unknown : public Symbol {
  private:
    char m_value;
  public:
    Unknown(char value): Symbol(SymbolType::UNKNOWN), m_value(value) {};
    char getChar() const {return m_value;};
};


#endif
