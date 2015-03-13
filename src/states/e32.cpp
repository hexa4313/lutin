#include "e32.h"
#include "../state.h"

E32::E32 (std::string name) : State(name)
{

}

bool E32::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
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
    case I :
        stateMachine.setState(s, new E3);
        break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}