#include "vardeclist.h"

void VarDecList::toString(std::ostream &o) const {

  auto len = m_vars.size();

  for(size_t i = 0; i < len; ++i)
  {
    o << *m_vars[i];
    if(i != len - 1)
      o << std::endl;
  }
}