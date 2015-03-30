#include "e12.h"

#include "e22.h"
#include "../ast/declaration/vardeclist.h"

bool E12::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  if(s->getType() == SymbolType::VG) {
    stateMachine.setState(s, std::make_shared<E22>());
    return true;
  }
  //Error case : coma forgotten -> Implicitly added
  else if(s->getType() != SymbolType::PV) {

    if(s->getType() == SymbolType::ID) {

      std::cerr << "Erreur syntaxique (" << s->getLine() << ":";
      std::cerr << s->getCol() << ") symbole , probablement attendu" << std::endl;

      auto e22 = std::make_shared<E22>();
      stateMachine.setState(std::make_shared<Symbol>(SymbolType::VG), e22);

      return e22->transition(stateMachine, s);
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

    auto v = std::dynamic_pointer_cast<VarDecList>(symbols[0]);

    auto e1 = stateMachine.curState();

    // reduction
    if(!e1->transition(stateMachine, v)) {
      return false;
    }

    auto e2 = stateMachine.curState();
    return e2->transition(stateMachine, s);
  }

}
