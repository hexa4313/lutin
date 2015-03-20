#include "e14.h"
#include "../state.h"
#include "e23.h"

bool E14::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  if(s->getType() == SymbolType::VG) {
    stateMachine.setState(s, std::make_shared<E23>());
  }
  else {
    stateMachine.popStates(2);
    stateMachine.popSymbols(2);
    stateMachine.lastState()->transition(stateMachine, s);
  }

  return true;
}
