#include "e6.h"
#include "../state.h"

E6::E6 (std::string name) : State(name)
{

}

bool E6::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case DL : 
      stateMachine.setState(s, E0);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
