#include "expdiv.h"

void ExpDiv::toString(std::ostream &o) const {
  o << "ExpDiv(" << *m_left << ", " << *m_right << ")";
}
