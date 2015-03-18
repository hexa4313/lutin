#include "e0.h"
#include "../state.h"

bool E0::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case DL :
      stateMachine.setState(s, std::make_shared<E1>());
      break;
    default :
      // TODO : gerer les erreurs
      break;
  }
  return false;
}
