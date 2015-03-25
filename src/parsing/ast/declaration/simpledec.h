#ifndef _LUTIN_DEC_H_
#define _LUTIN_DEC_H_

#include "../symbol.h"

class SimpleDec : public Symbol {
  public:
    SimpleDec(SymbolType type) : Symbol(type) {}
    virtual std::string getName() const = 0;
};

#endif //_LUTIN_DEC_H_
