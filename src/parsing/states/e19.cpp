#include "e19.h"
#include "../ast/instruction/identifier.h"

bool E19::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(1);
  auto symbols = stateMachine.popSymbols(1);

  auto id = boost::get<std::string>(symbols[0]->getValue());
  auto E = std::make_shared<Identifier>(id);

  auto e9 = stateMachine.lastState();

  //reduction
  if(!e9->transition(stateMachine, E)) {
    return false;
  }

  auto e17 = stateMachine.lastState();
  return e17->transition(stateMachine, s);

}
