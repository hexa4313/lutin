#include "e19.h"
#include "../state.h"

E19::E19 (std::string name) : State(name)
{

}
 
bool E19::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {
/*
    depiler E9
  switch(*s) {
    case E :
      stateMachine.setState(s, new E17);
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
  */
}
