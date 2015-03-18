#include "e41.h"
#include "../state.h"

bool E41::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case ID : 
      stateMachine.setState(s, std::make_shared<E19>());
      break;
    case E : 
      stateMachine.setState(s, std::make_shared<E32>());
      break;
    case VAL : 
      stateMachine.setState(s, std::make_shared<E18>());
      break;
    case PO : 
      stateMachine.setState(s, std::make_shared<E20>());
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
