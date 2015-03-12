#include "e2.h"
#include "../state.h"

E2::E2 (std::string name) : State(name)
{

}

bool E2::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case PV :
      stateMachine.setState(s, new E6);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
