#include "e30.h"
#include "../state.h"
#include "e37.h"


bool E30::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::E :
      stateMachine.setState(s, std::make_shared<E37>());
      return true;
    default :
      return false;
  }
}
