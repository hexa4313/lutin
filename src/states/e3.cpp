#include "e3.h"
#include "e8.h"
#include "e10.h"
#include "e9.h"
#include "e11.h"

bool E3::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::I :
    case SymbolType::I_W:
    case SymbolType::I_R:
      stateMachine.setState(s, std::make_shared<E8>());
      return true;
    case SymbolType::W :
      stateMachine.setState(s, std::make_shared<E9>());
      return true;
    case SymbolType::R :
      stateMachine.setState(s, std::make_shared<E10>());
      return true;
    case SymbolType::ID :
      stateMachine.setState(s, std::make_shared<E11>());
      return true;
    /*case "$" : 
      stateMachine.setState(s, ??);
      return true;*/
    default :
      return false;
  }
}
