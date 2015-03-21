#include "constdec.h"

void ConstDec::toString(std::ostream &o) const {
  o << "  " << "ConstDec(" << m_name << ", " << m_value << ")";
}