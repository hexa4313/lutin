#include "e9.h"
#include "../state.h"

E9::E9 (std::string name) : State(name)
{

}
 
bool E9::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case E :
      stateMachine.setState(s, new E17);
      break;
    case PO :
      stateMachine.setState(s, new E18);
      break;
    case ID :
      stateMachine.setState(s, new E19);
      break;
    case VAL :
      stateMachine.setState(s, new E20);
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
