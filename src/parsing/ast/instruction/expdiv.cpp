#include "expdiv.h"

void ExpDiv::toString(std::ostream &o) const {
  o << *m_left << "/" << *m_right;
}
