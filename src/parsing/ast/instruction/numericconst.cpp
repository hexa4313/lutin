#include "numericconst.h"

void NumericConst::toString(std::ostream &o) const {
  o << m_value;
}

std::vector<std::string> NumericConst::getIdentifiers() {
  std::vector<std::string> vars; // empty vector
  return vars;
}

std::shared_ptr<Expression> NumericConst::optimizeConstants(std::map<std::string, int>) {
  return std::make_shared<NumericConst>(m_value);
}