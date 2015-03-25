#include "variable.h"

void Variable::toString(std::ostream &o) const {
  o << m_name;
}

std::vector<std::string> Variable::getVariables() {
  std::vector<std::string> vars;
  vars.push_back(m_name);
  return vars;
}