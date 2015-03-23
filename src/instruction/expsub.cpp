#include "expsub.h"

void ExpSub::toString(std::ostream &o) const {
  o << "ExpSub(" << m_left << " - " << m_right << ")";
}
