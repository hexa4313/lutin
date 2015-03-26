#include "constdeclist.h"

void ConstDecList::toString(std::ostream &o) const {

  auto len = m_consts.size();

  for(size_t i = 0; i < len; ++i)
  {
    o << *m_consts[i];
    if(i != len - 1)
      o << std::endl;
  }
}