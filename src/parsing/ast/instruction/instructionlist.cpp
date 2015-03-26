#include "instructionlist.h"

#include <algorithm>
#include "read.h"
#include "assign.h"

void InstructionList::toString(std::ostream &o) const {
  for(auto inst : m_instructions) {
    o << *inst << std::endl;
  }
}

std::shared_ptr<Instruction> InstructionList::lastAssignation(std::string id, std::shared_ptr<Instruction> instruction) {

  auto it = std::find(m_instructions.rbegin(), m_instructions.rend(), instruction);

  // Search backwards
  for(it++; it != m_instructions.rend(); ++it) {
    auto prevInstruction = *it;
    if(prevInstruction->getType() == SymbolType::I_R) {
      auto r = std::dynamic_pointer_cast <Read> (prevInstruction);
      if(r->getId() == id) {
        return r;
      }
    }
    else if(prevInstruction->getType() == SymbolType::AFF) {
      auto aff = std::dynamic_pointer_cast <Assign> (prevInstruction);
      if(aff->getId() == id) {
        return aff;
      }
    }
  }

  return nullptr;
}