#include "../state.h"
#include "e1.h"
#include "e2.h"
#include "e3.h"
#include "e4.h"
#include "e5.h"


bool E1::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    // equivalent to SymbolType::D
    case SymbolType::V :
    case SymbolType::C :
      stateMachine.setState(s, std::make_shared<E2>());
      return true;
    case SymbolType::IL :
      stateMachine.setState(s, std::make_shared<E3>());
      return true;
    case SymbolType::VAR :
      stateMachine.setState(s, std::make_shared<E4>());
      return true;
    case SymbolType::CST :
      stateMachine.setState(s, std::make_shared<E5>());
      return true;
    default :
      return false;
  }
}
