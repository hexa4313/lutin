#include "e38.h"
#include "../state.h"
#include "e9.h"

bool E38::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::E : 
      stateMachine.setState(s, std::make_shared<E9>());
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
