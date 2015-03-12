#include "e0.h"
#include "../state.h"

E0::E0 (std::string name) : State(name)
{

}

bool E0::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case DL :
      stateMachine.setState(s, new E1);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
