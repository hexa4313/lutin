#include "e20.h"
#include "../ast/instruction/numericconst.h"

bool E20::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(1);
  auto symbols = stateMachine.popSymbols(1);

  auto E = std::make_shared<NumericConst>(boost::get<int>(symbols[0]->getValue()));

  auto e9 = stateMachine.lastState();

  //reduction
  if(!e9->transition(stateMachine, E)) {
    return false;
  }

  auto e17 = stateMachine.lastState();
  return e17->transition(stateMachine, s);
}
