#include "e4.h"
#include "../state.h"

E4::E4 (std::string name) : State(name)
{

}
 
bool E4::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case V :
      stateMachine.setState(s, new E12);
      break;
    case id :
      stateMachine.setState(s, new E13);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
