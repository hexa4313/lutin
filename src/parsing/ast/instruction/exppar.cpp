#include "exppar.h"

void ExpPar::toString(std::ostream &o) const {
  o << "(" << *m_expr << ")";
}

std::vector<std::string> ExpPar::getIdentifiers() {
  std::vector<std::string> vars;
  vars.insert(vars.end(), m_expr->getIdentifiers().begin(), m_expr->getIdentifiers().end());
  return vars;
}