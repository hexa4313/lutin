#include "e10.h"
#include "../state.h"
 
bool E10::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case ID :
      stateMachine.setState(s, std::make_shared<E21>());
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
