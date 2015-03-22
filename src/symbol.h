#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include <boost/variant.hpp>
#include "symboltype.h"

class Symbol {

  protected:
    SymbolType m_type;
    boost::variant<int, std::string> m_value;
    virtual void toString(std::ostream& o) const;
    friend std::ostream& operator<<(std::ostream& o, const Symbol& s) {
      s.toString(o);
      return o;
    }

  public:
    Symbol(SymbolType type) : m_type(type) {}
    Symbol(SymbolType type, long num) : Symbol(type) { m_value = num; }
    Symbol(SymbolType type, std::string id) : Symbol(type) { m_value = id; }
    virtual ~Symbol() {}

    SymbolType getType() const { return m_type; }
    boost::variant<int, std::string> getValue() const;

    operator int() const { return static_cast<int>(m_type); }
    bool isInstructionKeyword() { return m_type == SymbolType::R || m_type == SymbolType::W || m_type == SymbolType::ID; }
};

#endif
