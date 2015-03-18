#include "e21.h"
#include "../state.h"

bool E21::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case I :
      stateMachine.setState(s, std::make_shared<E3>());
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
