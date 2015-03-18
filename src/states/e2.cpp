#include "e2.h"
#include "../state.h"

bool E2::transition (StateMachine & stateMachine, SymbolType type) {

  switch(type) {
    case PV :
      stateMachine.setState(s, std::make_shared<E6>());
      break;
    default :
      // TODO : gerer les erreurs
      break;
  }
  return false;
}
