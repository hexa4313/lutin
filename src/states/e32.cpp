#include "e32.h"
#include "../state.h"

E32::E32 (std::string name) : State(name)
{

}

bool E32::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case OPM :
      stateMachine.setState(s, new E31);
      break;
      case OPA :
      stateMachine.setState(s, new E31);
      break;
    /*case "$" : 
      stateMachine.setState(s, ??);
      break;*/
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
