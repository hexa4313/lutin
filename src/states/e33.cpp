#include "e30.h"
#include "../state.h"

E30::E30 (std::string name) : State(name)
{

}

bool E30::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case VAL :
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
