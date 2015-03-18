#include "e2.h"
#include "../state.h"
#include "e6.h"

bool E2::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::PV :
      stateMachine.setState(s, std::make_shared<E6>());
      break;
    default :
      // TODO : gerer les erreurs
      break;
  }
  return false;
}
