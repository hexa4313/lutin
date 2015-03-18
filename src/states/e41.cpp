#include "e41.h"
#include "../state.h"

bool E41::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::ID : 
      stateMachine.setState(s, std::make_shared<E19>());
      break;
    case SymbolType::E : 
      stateMachine.setState(s, std::make_shared<E32>());
      break;
    case SymbolType::VAL :
      stateMachine.setState(s, std::make_shared<E20>());
      break;
    case SymbolType::PO : 
      stateMachine.setState(s, std::make_shared<E20>());
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
