#include "e21.h"
#include "../ast/instruction/read.h"

bool E21::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(2);
  auto symbols = stateMachine.popSymbols(2);

  auto id = boost::get<std::string>(symbols[0]->getValue());
  auto I = std::make_shared<Read>(id);

  auto e3 = stateMachine.curState();

  // reduction
  if(!e3->transition(stateMachine, I)) {
    return false;
  }

  auto e8 = stateMachine.curState();
  return e8->transition(stateMachine, s);
}
