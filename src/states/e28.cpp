#include "e28.h"
#include "../state.h"
#include "../instruction/expadd.h"

bool E28::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(1);
  stateMachine.popSymbols(1);

  auto OpA = std::make_shared<ExpAdd>();

  auto e17 = stateMachine.lastState();

  //reduction
  e17->transition(stateMachine, OpA);

  auto e30 = stateMachine.lastState();
  e30->transition(stateMachine, s);

  return true;
}
