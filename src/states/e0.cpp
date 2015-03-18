#include "e0.h"
#include "../state.h"
#include "e1.h"

bool E0::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case DL :
      stateMachine.setState(s, std::make_shared<E1>());
      break;
    default :
      // TODO : gerer les erreurs
      break;
  }
  return false;
}
