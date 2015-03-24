#include "e27.h"
#include "../state.h"
#include "../instruction/expsub.h"

bool E27::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(1);
  stateMachine.popSymbols(1);

  auto OpA = std::make_shared<ExpSub>();

  stateMachine.lastState()->transition(stateMachine, OpA);

  return true;
}
