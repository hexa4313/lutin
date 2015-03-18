#include "e24.h"
#include "../state.h"

bool E24::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case VAL :
      stateMachine.setState(s, new E35);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
