#include "e27.h"
#include "../ast/expression/expsub.h"

bool E27::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(1);
  stateMachine.popSymbols(1);

  auto OpA = std::make_shared<ExpSub>();

  auto e17 = stateMachine.curState();

  //reduction
  if(!e17->transition(stateMachine, OpA)) {
    return false;
  }

  auto e30 = stateMachine.curState();
  return e30->transition(stateMachine, s);
}
