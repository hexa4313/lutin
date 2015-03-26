#include "binaryexp.h"
#include "../../../interpreter/symboltable.h"

std::vector<std::string> BinaryExp::getIdentifiers() {
  std::vector<std::string> vars;
  auto mLeftVars = m_left->getIdentifiers();
  auto mRightVars = m_right->getIdentifiers();
  vars.insert(vars.end(), mLeftVars.begin(), mLeftVars.end());
  vars.insert(vars.end(), mRightVars.begin(), mRightVars.end());
  return vars;
}