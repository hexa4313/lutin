#include "expmult.h"

void ExpMult::toString(std::ostream &o) const {
  o << "ExpMult(" << m_left << " * " << m_right << ")";
}
