#include "e40.h"
#include "../ast/declaration/constdeclist.h"

bool E40::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(5);
  auto symbols = stateMachine.popSymbols(5);

  auto id = boost::get<std::string>(symbols[2]->getValue());
  auto value = boost::get<int>(symbols[0]->getValue());
  auto constDec = std::make_shared<ConstDec>(id, value);

  auto C = std::dynamic_pointer_cast<ConstDecList>(symbols[4]);
  C->addConstDec(constDec);

  // reduction
  auto e5 = stateMachine.curState();
  if(!e5->transition(stateMachine, C)) {
    return false;
  }

  auto e14 = stateMachine.curState();
  return e14->transition(stateMachine, s);
}
