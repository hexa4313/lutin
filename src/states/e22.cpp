#include "e22.h"
#include "../state.h"
#include "e33.h"

bool E22::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::ID : {
      auto e33 = std::make_shared<E33>();
      stateMachine.setState(s, e33);
      return e33->transition(stateMachine, nullptr);
    }
    default :
      return false;
  }
}
