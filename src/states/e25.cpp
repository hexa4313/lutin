#include "e25.h"
#include "../state.h"
#include "../instruction/expmult.h"

bool E25::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {


  auto states = stateMachine.popStates(1);
  auto symbols = stateMachine.popSymbols(1);

  auto opmul = std::make_shared<ExpMult>(); // TODO SET left and right expressions, where??

  stateMachine.lastState()->transition(stateMachine, opmul);

  return true;
}
