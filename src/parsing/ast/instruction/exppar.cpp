#include "exppar.h"

void ExpPar::toString(std::ostream &o) const {
  o << "(" << *m_expr << ")";
}

std::vector<std::string> ExpPar::getIdentifiers() {
  return m_expr->getIdentifiers();
}

int ExpPar::eval(std::shared_ptr<SymbolTable> m_table) const {
  return m_expr->eval(m_table);
}