#include "e18.h"
#include "../state.h"

bool E18::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case PO :
      stateMachine.setState(s, new E18);
      break;
    case E :
      stateMachine.setState(s, new E31);
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
