#include "numericconst.h"

void NumericConst::toString(std::ostream &o) const {
  o << "NumericConst(" << m_value << ")";
}
