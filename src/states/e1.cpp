#include "e1.h"
#include "../state.h"

E1::E1 (std::string name) : State(name)
{

}

bool E1::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case D :
      stateMachine.setState(s, new E2);
      break;
    case IL :
      stateMachine.setState(s, new E3);
      break;
    case VAR :
      stateMachine.setState(s, new E4);
      break;
    case CST :
      stateMachine.setState(s, new E5);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
