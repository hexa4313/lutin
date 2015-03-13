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
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
