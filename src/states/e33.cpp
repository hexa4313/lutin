#include "e33.h"
#include "../state.h"

E33::E33 (std::string name) : State(name)
{

}

bool E33::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
      case V :
        stateMachine.setState(s, new E4);
        break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
