#include "e21.h"

#include "../instruction/read.h"

bool E21::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(2);
  auto symbols = stateMachine.popSymbols(2);

  auto id = boost::get<std::string>(symbols[0]->getValue());
  auto I = std::make_shared<Read>(id);

  auto e3 = stateMachine.lastState();

  // reduction
  e3->transition(stateMachine, I);

  auto e8 = stateMachine.lastState();
  e8->transition(stateMachine, s);

  return true;
}
