#include "exppar.h"

void ExpPar::toString(std::ostream &o) const {
  o << "(" << *m_expr << ")";
}

std::vector<std::string> ExpPar::getIdentifiers() {
  return m_expr->getIdentifiers();
}