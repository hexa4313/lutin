#include "e28.h"
#include "../state.h"
#include "../instruction/expadd.h"

bool E28::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(1);
  stateMachine.popSymbols(1);

  auto OpA = std::make_shared<ExpAdd>();

  stateMachine.lastState()->transition(stateMachine, OpA);

  return true;
}
