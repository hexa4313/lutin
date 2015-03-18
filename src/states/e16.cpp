#include "e16.h"
#include "../state.h"

E16::E16 (std::string name) : State(name)
{

}
 
bool E16::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  /*
  depiler E8
  depiler E3
  depiler E1
  switch(*s) {
    case IL :
      stateMachine.setState(s, new E3);
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }*/
  return false;
}
