#include "e29.h"
#include "../state.h"

E29::E29 (std::string name) : State(name)
{

}

bool E29::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case E :
      stateMachine.setState(s, new E36);
      return true;
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
