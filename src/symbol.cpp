#include "symbol.h"

#include <assert.h>

Symbol::SymbolValue Symbol::GetValue() {
  assert(m_type == SymbolType::ID || m_type != SymbolType::VAL);

  return m_value;
}