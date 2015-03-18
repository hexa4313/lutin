#include "e29.h"
#include "../state.h"


bool E29::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case E :
      stateMachine.setState(s, std::make_shared<E36>());
      return true;
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
