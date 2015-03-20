#include "e34.h"
#include "../state.h"
#include "e39.h"


bool E34::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::EQ :
      stateMachine.setState(s, std::make_shared<E39>());
      return true;
    default :
      return false;
  }
}
