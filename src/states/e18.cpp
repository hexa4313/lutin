#include "e18.h"
#include "e31.h"
#include "e19.h"
#include "e20.h"

bool E18::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::PO :
      stateMachine.setState(s, std::make_shared<E18>());
      return true;
    case SymbolType::E :
    case SymbolType::E_CNUM:
    case SymbolType::E_VAL:
      stateMachine.setState(s, std::make_shared<E31>());
      return true;
    case SymbolType::ID :
      stateMachine.setState(s, std::make_shared<E19>());
      return true;
    case SymbolType::VAL :
      stateMachine.setState(s, std::make_shared<E20>());
      return true;
    default :
      return false;
  }
}
