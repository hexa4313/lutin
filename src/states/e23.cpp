#include "e23.h"
#include "../state.h"

E23::E23 (std::string name) : State(name)
{

}

bool E23::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case ID :
      stateMachine.setState(s, new E34);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
