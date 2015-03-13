#include "e31.h"
#include "../state.h"

E31::E31 (std::string name) : State(name)
{

}

bool E31::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case "PF" :
      stateMachine.setState(s, new E38);
      break;
    case MUL :
      stateMachine.setState(s, new E25);
      break;
    case DIV :
      stateMachine.setState(s, new E26);
      break;
    case SUB :
      stateMachine.setState(s, new E27);
      break;
    case ADD :
      stateMachine.setState(s, new E28);
      break;
    case OPM :
      stateMachine.setState(s, new E29);
      break;
    case OPA :
      stateMachine.setState(s, new E30);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
