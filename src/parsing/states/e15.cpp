#include "e15.h"

#include "e24.h"

bool E15::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto e24 = std::make_shared<E24>();

  switch(s->getType()) {
    case SymbolType::EQ:
      stateMachine.setState(s, e24);
      return true;
    default :
      std::cerr << "Erreur syntaxique (" << s->getLine() << ":";
      std::cerr << s->getCol() << ") operateur = attendu" << std::endl;

      stateMachine.setState(std::make_shared<Symbol>(SymbolType::EQ), e24);

      return e24->transition(stateMachine, s);
  }
}
