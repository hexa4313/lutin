#include "e4.h"

#include "e12.h"
#include "e13.h"
 
bool E4::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::V :
      stateMachine.setState(std::make_shared<E12>());
      return true;
    case SymbolType::ID : {
      auto e13 = std::make_shared<E13>();
      stateMachine.setState(s, e13);
      return e13->transition(stateMachine, nullptr);
    }
    default :
      return false;
  }
}
