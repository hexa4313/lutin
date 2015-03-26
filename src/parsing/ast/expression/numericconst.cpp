#include "numericconst.h"

void NumericConst::toString(std::ostream &o) const {
  o << m_value;
}

std::vector<std::string> NumericConst::getIdentifiers() {
  std::vector<std::string> vars; // empty vector
  return vars;
}

int NumericConst::eval(std::shared_ptr<SymbolTable> m_table) const {
  return m_value;
}

std::shared_ptr<Expression> NumericConst::optimize(std::shared_ptr<DeclarationList> declList) {
  return std::make_shared<NumericConst>(m_value);
}