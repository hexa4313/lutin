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

std::shared_ptr<Expression> Identifier::optimizeConstants(std::map<std::string, int> csts) {

  auto value = csts.find(m_name);

  if(value != csts.end()) {
    return std::make_shared<NumericConst>(csts[m_name]);
  }
  else {
    return std::make_shared<Identifier>(m_name);
  }
}