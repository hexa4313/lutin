#include "e22.h"
#include "../state.h"

E22::E22 (std::string name) : State(name)
{

}

bool E22::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case ID :
      stateMachine.setState(s, new E33);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
