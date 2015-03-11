#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include <memory>
#include "symboltype.h"

class Symbol {

  union SymbolValue {
    std::string id;
    long value;
  };

  protected:
    SymbolType m_type;
    SymbolValue m_value;

  public:
    Symbol(SymbolType type) : m_type(type) {}
    Symbol(SymbolType type, int value) : Symbol(type), m_value(value) {}
    Symbol(SymbolType type, std::string id) : Symbol(type), m_value(id) {}
    virtual ~Symbol() {}
    void print();
    SymbolValue GetValue();
    operator int() const { return static_cast<int>(m_type); }
};

#endif
