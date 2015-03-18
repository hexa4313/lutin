#include "e5.h"
#include "../state.h"
#include "e14.h"
#include "e15.h"

bool E5::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::C :
      stateMachine.setState(s, std::make_shared<E14>());
      break;
    case SymbolType::ID :
      stateMachine.setState(s, std::make_shared<E15>());
      break;
    default :
      // TODO : gerer les erreurs
      break;
  }
  return false;
}
