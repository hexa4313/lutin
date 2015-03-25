#include "e0.h"
#include "../instruction/instructionlist.h"
#include "e1.h"

bool E0::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {
  if(s->getType() == SymbolType::DL) {
    stateMachine.setState(s, std::make_shared<E1>());
    return true;
  }
  else {
    return false;
  }
}
