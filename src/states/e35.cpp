#include "e35.h"
#include "../state.h"

E35::E35 (std::string name) : State(name)
{

}

bool E35::transition (StateMachine & stateMachine, Symbol * s) {

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
