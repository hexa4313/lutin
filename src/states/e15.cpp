#include "e15.h"
#include "../state.h"
#include "e24.h"

bool E15::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::EQ :
      stateMachine.setState(s, std::make_shared<E24>());
      return true;
      
    default :
      return false;
  }
}
