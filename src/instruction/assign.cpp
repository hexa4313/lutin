#include "assign.h"

void Assign::toString(std::ostream &o) const {
  o << "    " << "Assign(" << m_id << ", " << *m_expr << ")";
}
