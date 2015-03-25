#include "exppar.h"

void ExpPar::toString(std::ostream &o) const {
  o << "(" << *m_expr << ")";
}

std::vector<std::string> ExpPar::getVariables() {
  std::vector<std::string> vars;
  vars.insert(vars.end(), m_expr->getVariables().begin(), m_expr->getVariables().end());
  return vars;
}