#include "e18.h"
#include "../state.h"

E18::E18 (std::string name) : State(name)
{

}
 
bool E18::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case PO :
      stateMachine.setState(s, new E18);
      break;
    case E :
      stateMachine.setState(s, new E31);
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
