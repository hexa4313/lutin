#include "identifier.h"
#include "numericconst.h"

void Identifier::toString(std::ostream &o) const {
  o << m_name;
}

std::vector<std::string> Identifier::getIdentifiers() {
  std::vector<std::string> vars;
  vars.push_back(m_name);
  return vars;
}

std::shared_ptr<Expression> Identifier::optimize(std::shared_ptr<DeclarationList> declList) {

  std::map<std::string, int> consts = declList->getConstants();

  auto value = consts.find(m_name);

  if(value != consts.end()) {
    return std::make_shared<NumericConst>(consts[m_name]);
  }
  else {
    return std::make_shared<Identifier>(m_name);
  }
}

int Identifier::eval(std::shared_ptr<SymbolTable> m_table) const {
  return m_table->get(m_name);
}