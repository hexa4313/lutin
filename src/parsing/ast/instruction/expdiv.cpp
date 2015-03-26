#include "expdiv.h"

void ExpDiv::toString(std::ostream &o) const {
  o << *m_left << "/" << *m_right;
}

int ExpDiv::eval(std::shared_ptr<SymbolTable> m_table) const {
  return m_left->eval(m_table) / m_right->eval(m_table);
}