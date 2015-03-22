#include "e27.h"
#include "../state.h"
#include "../instruction/expsub.h"

bool E27::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {
  stateMachine.popStates(1);
  auto symbols = stateMachine.popSymbols(1);

  auto opsub = std::make_shared<ExpSub>();

  stateMachine.lastState()->transition(stateMachine, opsub);

  return true;
}
