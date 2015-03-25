#include "expsub.h"

void ExpSub::toString(std::ostream &o) const {
  o << *m_left << "-" << *m_right;
}
