#include "symbol.h"

#include <assert.h>

boost::variant<int, std::string>  Symbol::GetValue() {
  assert(m_type == SymbolType::ID || m_type != SymbolType::VAL);

  return m_value;
}