#include "e10.h"
#include "../state.h"
 
bool E10::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case ID :
      stateMachine.setState(s, new E21);
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
