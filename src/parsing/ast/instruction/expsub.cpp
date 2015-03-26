#include "expsub.h"

void ExpSub::toString(std::ostream &o) const {
  o << *m_left << "-" << *m_right;
}

int ExpSub::eval(std::shared_ptr<SymbolTable> m_table) const {
  return m_left->eval(m_table) - m_right->eval(m_table);
}