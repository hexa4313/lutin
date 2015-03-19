#include "e3.h"
#include "../state.h"
#include "e7.h"
#include "e8.h"
#include "e10.h"
#include "e9.h"

bool E3::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::I :
      stateMachine.setState(s, std::make_shared<E8>());
      break;
    case SymbolType::W :
      stateMachine.setState(s, std::make_shared<E9>());
      break;
    case SymbolType::R :
      stateMachine.setState(s, std::make_shared<E10>());
      break;
    case SymbolType::ID :
      stateMachine.setState(s, std::make_shared<E11>());
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
