#include "e14.h"

#include "e23.h"
#include "../ast/declaration/constdeclist.h"

#include <iostream>

bool E14::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  if(s->getType() == SymbolType::VG) {
    stateMachine.setState(s, std::make_shared<E23>());
    return true;
  }
  //Error case : coma forgotten -> Implicitly added
  else if(s->getType() != SymbolType::PV) {

    if(s->getType() == SymbolType::ID) {
      std::cerr << "Erreur syntaxique (" << s->getLine() << ":";
      std::cerr << s->getCol() << ") symbole , probablement attendu" << std::endl;

      auto e23 = std::make_shared<E23>();
      stateMachine.setState(std::make_shared<Symbol>(SymbolType::VG), e23);

      return e23->transition(stateMachine, s);
    }
    else {
      std::cerr << "Erreur syntaxique (" << s->getLine() << ":";
      std::cerr << s->getCol() << ") symbole ; attendu" << std::endl;

      if(!this->transition(stateMachine, std::make_shared<Symbol>(SymbolType::PV))) {
        return false;
      }

      auto e1 = stateMachine.curState();
      return e1->transition(stateMachine, s);

    }
  }
  else {
    stateMachine.popStates(2);
    auto symbols = stateMachine.popSymbols(2);

    auto c = std::dynamic_pointer_cast<ConstDecList>(symbols[0]);

    auto e1 = stateMachine.curState();

    // reduction
    if(!e1->transition(stateMachine, c)) {
      return false;
    }

    auto e2 = stateMachine.curState();
    return e2->transition(stateMachine, s);
  }
}
