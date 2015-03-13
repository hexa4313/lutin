#include "e10.h"
#include "../state.h"

E10::E10 (std::string name) : State(name)
{

}
 
bool E10::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case ID :
      stateMachine.setState(s, new E21);
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
