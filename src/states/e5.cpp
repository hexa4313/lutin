#include "e5.h"
#include "../state.h"
 
bool E5::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case C :
      stateMachine.setState(s, std::make_shared<E14>());
      break;
    case id :
      stateMachine.setState(s, std::make_shared<E15>());
      break;
    default :
      // TODO : gerer les erreurs
      break;
  }
  return false;
}
