#include "binaryexp.h"

std::vector<std::string> BinaryExp::getVariables() {
  std::vector<std::string> vars;
  auto mLeftVars = m_left->getVariables();
  auto mRightVars = m_right->getVariables();
  vars.insert(vars.end(), mLeftVars.begin(), mLeftVars.end());
  vars.insert(vars.end(), mRightVars.begin(), mRightVars.end());
  return vars;
}