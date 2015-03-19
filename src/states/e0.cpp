#include "e0.h"
#include "../state.h"
#include "e1.h"

bool E0::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::DL :
      stateMachine.setState(s, std::make_shared<E1>());
      return true;
    default :
      // TODO : gerer les erreurs
      return false;
  }
}
