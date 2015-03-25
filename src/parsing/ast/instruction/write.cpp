#include "write.h"

void Write::toString(std::ostream &o) const {
  o << "ecrire " << *m_exp << ";";
}
