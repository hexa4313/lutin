#include "expmult.h"

void ExpMult::toString(std::ostream &o) const {
  o << *m_left << "*" << *m_right;
}
