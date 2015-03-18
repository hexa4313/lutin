#include "e39.h"
#include "../state.h"
#include "e40.h"


bool E39::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::VAL :
      stateMachine.setState(s, std::make_shared<E40>());
      break;
    /*case "$" : 
      stateMachine.setState(s, ??);
      break;*/
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
