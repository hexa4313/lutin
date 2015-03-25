#include "constdec.h"

void ConstDec::toString(std::ostream &o) const {
  o << "const " << m_name << " = " << m_value << ";";
}