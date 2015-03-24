#include "vardeclist.h"

void VarDecList::toString(std::ostream &o) const {
  o << "    " << "VarDecList([" << std::endl;
  for(auto dec : m_vars) {
    o << "    " << *dec << std::endl;
  }

  o << "    " << "])";
}