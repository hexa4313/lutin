#include "expadd.h"

void ExpAdd::toString(std::ostream &o) const {
  o << "ExpAdd(" << *m_left << ", " << *m_right << ")";
}
