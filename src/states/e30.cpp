#include "e30.h"

#include "e37.h"
#include "e18.h"
#include "e19.h"
#include "e20.h"


bool E30::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::E_CNUM :
    case SymbolType::E_VAL :
    case SymbolType::E :
      stateMachine.setState(s, std::make_shared<E37>());
      return true;
    case SymbolType::PO :
      stateMachine.setState(s, std::make_shared<E18>());
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
