#include "e12.h"
#include "../state.h"

bool E12::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  if(s->getType() == SymbolType::VG) {
    stateMachine.setState(s, new E22);
  }
  else {
    stateMachine.popStates(2);
    stateMachine.popSymbols(2);
    stateMachine.lastState()->transition(stateMachine, s);
  }

}
