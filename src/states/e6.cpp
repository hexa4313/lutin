#include "e6.h"

bool E6::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto symbols = stateMachine.popSymbols(3);
  stateMachine.popStates(3);

  auto e0 = stateMachine.lastState();
  auto dl = std::dynamic_pointer_cast<DeclarationList>(symbols[2]);
  auto d =  std::dynamic_pointer_cast<Declaration>(symbols[1]);
  dl->addDeclaration(d);

  //reduction
  if(!e0->transition(stateMachine, dl)) {
    return false;
  }

  auto e1 = stateMachine.lastState();
  return e1->transition(stateMachine, s);

}