#include "e2.h"
#include "e6.h"

#include <iostream>

bool E2::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto e6 = std::make_shared<E6>();

  switch(s->getType()) {
    case SymbolType::PV :
      stateMachine.setState(s, e6);
      return true;
    default :
      std::cerr << "Erreur syntaxique (" << s->getLine() << ":";
      std::cerr << s->getCol() << ") symbole ; attendu" << std::endl;

      stateMachine.setState(std::make_shared<Symbol>(SymbolType::PV), e6);

      return e6->transition(stateMachine, s);
  }
}
