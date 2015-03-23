#include "variable.h"

void Variable::toString(std::ostream &o) const {
  o << "Variable(" << m_name << ")";
}
