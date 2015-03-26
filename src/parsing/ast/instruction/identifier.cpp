#include "identifier.h"

void Identifier::toString(std::ostream &o) const {
  o << m_name;
}

std::vector<std::string> Identifier::getIdentifiers() {
  std::vector<std::string> vars;
  vars.push_back(m_name);
  return vars;
}

int Identifier::eval(std::shared_ptr<SymbolTable> m_table) const {
  return m_table->get(m_name);
}