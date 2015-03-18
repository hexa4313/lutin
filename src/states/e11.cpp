#include "e11.h"
#include "../state.h"

E11::E11 (std::string name) : State(name)
{

}
 
bool E11::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case AFF :
      stateMachine.setState(s, new E41);
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
