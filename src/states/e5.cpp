#include "e5.h"
#include "../state.h"

E5::E5 (std::string name) : State(name)
{

}
 
bool E5::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case C :
      stateMachine.setState(s, new E14);
      break;
    case id :
      stateMachine.setState(s, new E15);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
