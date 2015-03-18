#include "e9.h"
#include "../state.h"
 
bool E9::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case E :
      stateMachine.setState(s, std::make_shared<E17>());
      break;
    case PO :
      stateMachine.setState(s, std::make_shared<E18>());
      break;
    case ID :
      stateMachine.setState(s, std::make_shared<E19>());
      break;
    case VAL :
      stateMachine.setState(s, std::make_shared<E20>());
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
