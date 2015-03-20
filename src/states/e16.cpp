#include "e16.h"
#include "../state.h"

bool E16::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  /*
  depiler E8
  depiler E3
  depiler E1
  switch(s->getType()) {
    case SymbolType::IL :
      stateMachine.setState(s, std::make_shared<E3>());
      return true;
      
    default :
    // TODO : gerer les erreurs
      return false;
  }*/
  return false;
}
