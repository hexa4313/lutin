#include "e22.h"
#include "../state.h"

bool E22::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::ID :
      stateMachine.setState(s, std::make_shared<E33>());
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
