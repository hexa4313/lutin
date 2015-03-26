#include "instructionlist.h"

void InstructionList::toString(std::ostream &o) const {
  for(auto inst : m_instructions) {
    o << *inst << std::endl;
  }
}
