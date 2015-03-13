#include "e40.h"
#include "../state.h"

E40::E40 (std::string name) : State(name)
{

}

bool E40::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case C : 
      stateMachine.setState(s, new E5);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
