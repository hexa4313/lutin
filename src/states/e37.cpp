#include "e37.h"
#include "../state.h"

bool E37::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case MUL :
      stateMachine.setState(s, std::make_shared<E25>());
      break;
    case DIV :
      stateMachine.setState(s, std::make_shared<E26>());
      break;
    case SUB :
      stateMachine.setState(s, std::make_shared<E27>());
      break;
    case ADD :
      stateMachine.setState(s, std::make_shared<E28>());
      break;
    case OPM :
      stateMachine.setState(s, std::make_shared<E29>());
      break;
    case OPA :
      stateMachine.setState(s, std::make_shared<E30>());
      break;
    case E : 
      stateMachine.setState(s, std::make_shared<E9>());
      break;*/
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
