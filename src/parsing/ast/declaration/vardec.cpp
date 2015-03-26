#include "vardec.h"

void VarDec::toString(std::ostream &o) const {
  o << "var " << m_name << ";";
}