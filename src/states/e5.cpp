#include "e5.h"
#include "../state.h"
#include "e14.h"
#include "e15.h"

bool E5::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::C :
      stateMachine.setState(s, std::make_shared<E14>());
      return true;
    case SymbolType::ID : {
      auto e15 = std::make_shared<E15>();
      stateMachine.setState(s, e15);
      return e15->transition(stateMachine, nullptr);
    }
    default :
      return false;
  }
}
