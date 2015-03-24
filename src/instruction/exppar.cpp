#include "exppar.h"

void ExpPar::toString(std::ostream &o) const {
  o << "ExpPar(" << *m_expr << ")";
}
