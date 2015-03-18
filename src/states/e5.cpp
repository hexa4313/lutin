#include "e5.h"
#include "../state.h"
 
bool E5::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

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
