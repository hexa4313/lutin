#include "e12.h"
#include "../state.h"

E12::E12 (std::string name) : State(name)
{

}
 
bool E12::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case VG :
      stateMachine.setState(s, new E22);
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
