#include "e23.h"
#include "e34.h"

#include <iostream>

bool E23::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::ID :
      stateMachine.setState(s, std::make_shared<E34>());
      return true;
    default :
      std::cerr << "Erreur syntaxique (" << s->getLine() << ":";
      std::cerr << s->getCol() << ") symbole identifiant attendu" << std::endl;
      return false;
  }
}
