#include "e22.h"
#include "../state.h"

bool E22::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case ID :
      stateMachine.setState(s, new E33);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
