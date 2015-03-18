#include "e20.h"
#include "../state.h"

bool E20::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

    /* 
    depiler E9
    switch(s->getType()) {
        case E :
          stateMachine.setState(s, std::make_shared<E17>());
          break;
        default :
        // TODO : gerer les erreurs
          break;
  }

      */
  return false;
}
