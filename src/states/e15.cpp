#include "e15.h"
#include "../state.h"

E15::E15 (std::string name) : State(name)
{

}
 
bool E15::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case EQ :
      stateMachine.setState(s, new E24);
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
