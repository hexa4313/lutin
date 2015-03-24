#include "e19.h"

#include "../instruction/variable.h"

bool E19::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(1);
  auto symbols = stateMachine.popSymbols(1);

  auto id = boost::get<std::string>(symbols[0]->getValue());
  auto E = std::make_shared<Variable>(id);

  auto e9 = stateMachine.lastState();

  //reduction
  e9->transition(stateMachine, E);

  auto e17 = stateMachine.lastState();
  e17->transition(stateMachine, s);

  return false;

}
