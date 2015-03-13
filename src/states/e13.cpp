#include "e13.h"
#include "../state.h"

E13::E13 (std::string name) : State(name)
{

}
 
bool E13::transition (StateMachine & stateMachine, Symbol * s) {

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
