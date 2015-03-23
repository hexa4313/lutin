#include "write.h"

void Write::toString(std::ostream &o) const {
  o << "    " << "Write(" << m_exp << ")";
}
