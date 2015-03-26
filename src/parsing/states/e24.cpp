#include "e24.h"
#include "e35.h"

bool E24::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::VAL :
      stateMachine.setState(s, std::make_shared<E35>());
      return true;
    default :
      return false;
  }
}
