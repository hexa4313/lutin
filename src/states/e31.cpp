#include "e31.h"
#include "../state.h"


bool E31::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case "PF" :
      stateMachine.setState(s, std::make_shared<E38>());
      break;
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
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
