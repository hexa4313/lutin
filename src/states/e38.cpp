#include "e38.h"
#include "../state.h"

bool E38::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case E : 
      stateMachine.setState(s, new E9);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
