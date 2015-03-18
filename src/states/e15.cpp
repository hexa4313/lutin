#include "e15.h"
#include "../state.h"

bool E15::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case EQ :
      stateMachine.setState(s, std::make_shared<E24>());
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
