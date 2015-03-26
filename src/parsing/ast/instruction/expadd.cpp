#include "expadd.h"

void ExpAdd::toString(std::ostream &o) const {
  o << *m_left << "+" << *m_right;
}
