#include "e29.h"
#include "../state.h"

#include "e18.h"
#include "e19.h"
#include "e20.h"
#include "e36.h"

bool E29::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::E_PAR:
    case SymbolType::E_CNUM:
    case SymbolType::E_VAL:
    case SymbolType::OP_A:
    case SymbolType::OP_M:
      stateMachine.setState(s, std::make_shared<E36>());
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
