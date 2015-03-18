#include "e3.h"
#include "../state.h"

bool E3::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case I :
      stateMachine.setState(s, new E7);
      break;
    case W :
      stateMachine.setState(s, new E8);
      break;
    case R :
      stateMachine.setState(s, new E9);
      break;
    case ID :
      stateMachine.setState(s, new E10);
      break;
    /*case "$" : 
      stateMachine.setState(s, ??);
      break;*/
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
