#include "e30.h"
#include "../state.h"


bool E30::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case E :
      stateMachine.setState(s, std::make_shared<E37>());
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
