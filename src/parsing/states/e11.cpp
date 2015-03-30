#include "e11.h"
#include "e41.h"

#include <iostream>

bool E11::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto e41 = std::make_shared<E41>();

  switch(s->getType()) {
    case SymbolType::AFF :
      stateMachine.setState(s, e41);
      return true;
    default :
      std::cerr << "Erreur syntaxique (" << s->getLine() << ":";
      std::cerr << s->getCol() << ") operateur := attendu" << std::endl;

      stateMachine.setState(std::make_shared<Symbol>(SymbolType::AFF), e41);

      return e41->transition(stateMachine, s);
  }
}
