#include "e20.h"
#include "../state.h"

#include "../instruction/numericconst.h"

bool E20::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto states = stateMachine.popStates(1);
  auto symbols = stateMachine.popSymbols(1);

  auto val = std::make_shared<NumericConst>(boost::get<int>(symbols[0]->getValue()));

  stateMachine.lastState()->transition(stateMachine, val); // type E?

  return false;
}
