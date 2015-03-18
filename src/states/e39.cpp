#include "e39.h"
#include "../state.h"

E39::E39 (std::string name) : State(name)
{

}

bool E39::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case VAL :
      stateMachine.setState(s, new E40);
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
