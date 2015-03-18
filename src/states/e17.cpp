#include "e17.h"
#include "../state.h"

bool E17::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

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
      
    default :
    /*
    depiler E9
    depiler E3
    stateMachine.setState(s, std::make_shared<E8>());
    */
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
