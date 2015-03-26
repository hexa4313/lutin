#include "e15.h"
#include "e24.h"

bool E15::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {
  if(s->getType() == SymbolType::EQ) {
    stateMachine.setState(s, std::make_shared<E24>());
    return true;
  }
  else {
    return false;
  }
}
