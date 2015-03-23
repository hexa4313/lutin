#include "e20.h"
#include "../state.h"

#include "../instruction/numericconst.h"

bool E20::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(1);
  auto symbols = stateMachine.popSymbols(1);

  auto E = std::make_shared<NumericConst>(boost::get<int>(symbols[0]->getValue()));

  auto e9 = stateMachine.lastState();

  //reduction
  e9->transition(stateMachine, E);

  auto e17 = stateMachine.lastState();
  e17->transition(stateMachine, s);

  return false;
}
