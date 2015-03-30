#include "e22.h"
#include "e33.h"

#include <iostream>

bool E22::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::ID :
      stateMachine.setState(s, std::make_shared<E33>());
      return true;
    default :
      std::cerr << "Erreur syntaxique (" << s->getLine() << ":";
      std::cerr << s->getCol() << ") symbole identifiant attendu" << std::endl;
      return false;
  }
}
