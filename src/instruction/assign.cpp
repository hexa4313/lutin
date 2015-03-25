#include "assign.h"

void Assign::toString(std::ostream &o) const {
  o << m_id << " := " << *m_expr << ";";
}
