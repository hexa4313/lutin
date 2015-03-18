#include "e8.h"
#include "../state.h"

E8::E8 (std::string name) : State(name)
{

}
 
bool E8::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case PV :
      stateMachine.setState(s, new E16);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
