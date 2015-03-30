#include "e34.h"

#include "e39.h"

bool E34::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto e39 = std::make_shared<E39>();

  switch(s->getType()) {
    case SymbolType::EQ:
      stateMachine.setState(s, e39);
      return true;
    default :
      std::cerr << "Erreur syntaxique operateur = attendu" << std::endl;

      stateMachine.setState(std::make_shared<Symbol>(SymbolType::AFF), e39);

      return e39->transition(stateMachine, s);
  }
}
