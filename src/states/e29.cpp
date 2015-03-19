#include "e29.h"
#include "../state.h"

#include "e18.h"
#include "e19.h"
#include "e20.h"
#include "e36.h"

bool E29::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::E :
      stateMachine.setState(s, std::make_shared<E36>());
      break;
    case SymbolType::PO :
      stateMachine.setState(s, std::make_shared<E18>());
      break;
    case SymbolType::ID :
      stateMachine.setState(s, std::make_shared<E19>());
      break;
    case SymbolType::VAL :
      stateMachine.setState(s, std::make_shared<E20>());
      break;

    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
