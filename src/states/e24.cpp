#include "e24.h"
#include "../state.h"

E24::E24 (std::string name) : State(name)
{

}

bool E24::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case VAL :
      stateMachine.setState(s, new E35);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
