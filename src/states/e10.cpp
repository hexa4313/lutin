#include "e10.h"
#include "../state.h"
#include "e21.h"

bool E10::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::ID :
      stateMachine.setState(s, std::make_shared<E21>());
      return true;
      
    default :
      return false;
  }
}
