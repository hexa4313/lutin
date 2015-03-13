#include "e14.h"
#include "../state.h"

E14::E14 (std::string name) : State(name)
{

}
 
bool E14::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case VG :
      stateMachine.setState(s, new E23);
      break;
    case D :
      stateMachine.setState(s, new E1);
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
