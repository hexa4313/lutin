#include "e4.h"

#include "e12.h"
#include "e13.h"
 
bool E4::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::V :
      stateMachine.setState(s, std::make_shared<E12>());
      break;
    case SymbolType::ID :
      stateMachine.setState(s, std::make_shared<E13>());
      break;
    default :
      // TODO : gerer les erreurs
      break;
  }
  return false;
}
