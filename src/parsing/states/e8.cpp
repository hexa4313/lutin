#include "e8.h"
#include "e16.h"

bool E8::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto e16 = std::make_shared<E16>();

  switch(s->getType()) {
    case SymbolType::PV :
      stateMachine.setState(s, e16);
      return true;
    default :
      std::cerr << "Erreur syntaxique symbole ; attendu" << std::endl;

      stateMachine.setState(std::make_shared<Symbol>(SymbolType::PV), e16);

      return e16->transition(stateMachine, s);
  }
}
