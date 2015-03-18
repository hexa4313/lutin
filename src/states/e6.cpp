#include <vector>
#include "e6.h"
#include "../declaration/declarationlist.h"

bool E6::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> type) {

  auto symbols = stateMachine.popSymbols(3);
  auto states = stateMachine.popStates(3);

  auto e0 = stateMachine.lastState();
  auto dl = std::dynamic_pointer_cast<DeclarationList>(symbols[2]);
  auto d =  std::dynamic_pointer_cast<Declaration>(symbols[1]);
  dl->addDeclaration(d);
  e0->transition(stateMachine, symbols[2]);

  return true;

}