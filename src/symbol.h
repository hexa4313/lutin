#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include <boost/variant.hpp>
#include "symboltype.h"

class Symbol {

  protected:
    SymbolType m_type;
    boost::variant<int, std::string> m_value;

  public:
    Symbol(SymbolType type) : m_type(type), m_value(nullptr) {}
    Symbol(SymbolType type, long num) : Symbol(type) { m_value = num; }
    Symbol(SymbolType type, std::string id) : Symbol(type) { m_value = id; }
    virtual ~Symbol() {}
    void print();
    SymbolType getType() { return m_type; }
    boost::variant<int, std::string> GetValue();
    operator int() const { return static_cast<int>(m_type); }
};

#endif
