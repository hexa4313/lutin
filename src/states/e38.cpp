#include "e38.h"
#include "../instruction/exppar.h"

bool E38::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(3);
  auto symbols = stateMachine.popSymbols(3);

  auto E = std::make_shared<ExpPar>(symbols[1]);

  auto e9 = stateMachine.lastState();

  // reduction
  e9->transition(stateMachine, E);

  auto e17 = stateMachine.lastState();
  e17->transition(stateMachine, s);

  return true;

}
