#include "e34.h"
#include "../state.h"

E34::E34 (std::string name) : State(name)
{

}

bool E34::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case EQ :
      stateMachine.setState(s, new E39);
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
