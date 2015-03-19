#include "e26.h"
#include "../state.h"
#include "../instruction/expdiv.h"


bool E26::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto states = stateMachine.popStates(1);
  auto symbols = stateMachine.popSymbols(1);

  auto opdiv = std::make_shared<ExpDiv>();

  stateMachine.lastState()->transition(stateMachine, opdiv);
}
