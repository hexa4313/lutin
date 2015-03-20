#include "e22.h"
#include "../state.h"
#include "e33.h"

bool E22::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::ID :
      stateMachine.setState(s, std::make_shared<E33>());
      return true;
    default :
      return false;
  }
}
