#include "e28.h"
#include "../ast/expression/expadd.h"

bool E28::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(1);
  stateMachine.popSymbols(1);

  auto OpA = std::make_shared<ExpAdd>();

  auto e17 = stateMachine.lastState();

  //reduction
  if(!e17->transition(stateMachine, OpA)) {
    return false;
  }

  auto e30 = stateMachine.lastState();
  return e30->transition(stateMachine, s);
}
