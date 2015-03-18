#include "e4.h"
#include "../state.h"
 
bool E4::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::V :
      stateMachine.setState(s, new E12);
      break;
    case SymbolType::ID :
      stateMachine.setState(s, new E13);
      break;
    default :
      // TODO : gerer les erreurs
      break;
  }
  return false;
}
