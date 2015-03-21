#include "constdeclist.h"

void ConstDecList::toString(std::ostream &o) const {
  o << "  " << "ConstDecList([" << std::endl;
  for(auto dec : m_consts) {
    o << "  " << *dec << std::endl;
  }

  o << "  " << "])";
}