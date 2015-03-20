#include "e23.h"
#include "../state.h"
#include "e34.h"

bool E23::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::ID :
      stateMachine.setState(s, std::make_shared<E34>());
      return true;
    default :
      return false;
  }
}
