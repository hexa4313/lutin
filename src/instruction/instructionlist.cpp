#include "instructionlist.h"

void InstructionList::toString(std::ostream &o) const {
  o << "  " << "InstructionList([" << std::endl;
  for(auto inst : m_instructions) {
    o << *inst << std::endl;
  }

  o << "  " << "])";
}
