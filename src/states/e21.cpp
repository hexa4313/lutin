#include "e21.h"
#include "../state.h"

E21::E21 (std::string name) : State(name)
{

}

bool E21::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case I :
      stateMachine.setState(s, new E3);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
