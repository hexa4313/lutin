#include "e19.h"
#include "../state.h"

#include "../instruction/variable.h"

bool E19::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto states = stateMachine.popStates(1);
  auto symbols = stateMachine.popSymbols(1);

  auto val = std::make_shared<Variable>(boost::get<std::string>(symbols[0]->getValue()));

  stateMachine.lastState()->transition(stateMachine, var->getType());
  return false;

}
