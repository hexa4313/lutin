#include "e28.h"
#include "../state.h"
#include "../instruction/expadd.h"

bool E28::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto states = stateMachine.popStates(1);
  auto symbols = stateMachine.popSymbols(1);

  auto opadd = std::make_shared<ExpAdd>();

  stateMachine.lastState()->transition(stateMachine, opadd);

  return true;
}
