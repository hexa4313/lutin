#include "e32.h"
#include "../state.h"
#include "e25.h"
#include "e26.h"
#include "e27.h"
#include "e28.h"
#include "e29.h"
#include "e30.h"
#include "e3.h"


bool E32::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::MUL :
      stateMachine.setState(s, std::make_shared<E25>());
      return true;
    case SymbolType::DIV :
      stateMachine.setState(s, std::make_shared<E26>());
      return true;
    case SymbolType::SUB :
      stateMachine.setState(s, std::make_shared<E27>());
      return true;
    case SymbolType::ADD :
      stateMachine.setState(s, std::make_shared<E28>());
      return true;
    case SymbolType::OP_M :
      stateMachine.setState(s, std::make_shared<E29>());
      return true;
    case SymbolType::OP_A :
      stateMachine.setState(s, std::make_shared<E30>());
      return true;
    case SymbolType::I :
        stateMachine.setState(s, std::make_shared<E3>());
        return true;
    default :
      return false;
  }
}
