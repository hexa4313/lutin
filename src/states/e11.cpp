#include "e11.h"
#include "../state.h"
#include "e41.h"

bool E11::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::AFF :
      stateMachine.setState(s, std::make_shared<E41>());
      break;
      
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
