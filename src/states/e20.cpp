#include "e20.h"
#include "../state.h"

E20::E20 (std::string name) : State(name)
{

}

bool E20::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

    /* 
    depiler E9
    switch(*s) {
        case E :
          stateMachine.setState(s, new E17);
          break;
        default :
        // TODO : gerer les erreurs
          break;
  }

      */
  return false;
}
