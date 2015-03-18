#include "e8.h"
#include "../state.h"
#include "e16.h"

bool E8::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::PV :
      stateMachine.setState(s, std::make_shared<E16>());
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
