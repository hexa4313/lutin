#include "e30.h"
#include "../state.h"

E30::E30 (std::string name) : State(name)
{

}

bool E30::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case E :
      stateMachine.setState(s, new E37);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
