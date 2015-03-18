#include "e31.h"
#include "../state.h"


bool E31::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::PF :
      stateMachine.setState(s, std::make_shared<E38>());
      break;
    case SymbolType::MUL :
      stateMachine.setState(s, std::make_shared<E25>());
      break;
    case SymbolType::DIV :
      stateMachine.setState(s, std::make_shared<E26>());
      break;
    case SymbolType::SUB :
      stateMachine.setState(s, std::make_shared<E27>());
      break;
    case SymbolType::ADD :
      stateMachine.setState(s, std::make_shared<E28>());
      break;
    case SymbolType::OPM :
      stateMachine.setState(s, std::make_shared<E29>());
      break;
    case SymbolType::OPA :
      stateMachine.setState(s, std::make_shared<E30>());
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
