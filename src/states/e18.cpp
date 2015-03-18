#include "e18.h"
#include "../state.h"

bool E18::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::PO :
      stateMachine.setState(s, std::make_shared<E18>());
      break;
    case SymbolType::E :
      stateMachine.setState(s, std::make_shared<E31>());
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
