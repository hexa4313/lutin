#include "e25.h"
#include "../ast/instruction/expmult.h"

bool E25::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(1);
  stateMachine.popSymbols(1);

  auto OpM = std::make_shared<ExpMult>();

  auto e17 = stateMachine.lastState();

  //reduction
  if(!e17->transition(stateMachine, OpM)) {
    return false;
  }

  auto e29 = stateMachine.lastState();
  return e29->transition(stateMachine, s);
}
