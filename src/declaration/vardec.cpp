#include "vardec.h"

void VarDec::toString(std::ostream &o) const {
  o << "  " << "VarDec(" << m_name;

  if(m_assigned) {
    o << ", " << m_value;
  }

  o << ")";
}