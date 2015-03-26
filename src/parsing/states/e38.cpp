#include "e38.h"
#include "../ast/expression/exppar.h"

bool E38::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(3);
  auto symbols = stateMachine.popSymbols(3);

  auto expr = std::dynamic_pointer_cast<Expression>(symbols[1]);
  auto E = std::make_shared<ExpPar>(expr);

  auto e9 = stateMachine.lastState();

  // reduction
  if(!e9->transition(stateMachine, E)) {
    return false;
  }

  auto e17 = stateMachine.lastState();
  return e17->transition(stateMachine, s);

}
