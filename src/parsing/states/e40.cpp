#include "e40.h"
#include "../ast/declaration/constdeclist.h"

bool E40::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(5);
  auto symbols = stateMachine.popSymbols(5);

  auto id = boost::get<std::string>(symbols[2]->getValue());
  auto value = boost::get<int>(symbols[0]->getValue());
  auto constDec = std::make_shared<ConstDec>(id, value);

  auto c = std::dynamic_pointer_cast<ConstDecList>(symbols[4]);
  c->addConstDec(constDec);


  auto e5 = stateMachine.lastState();

  // reduction
  if(!e5->transition(stateMachine, c)) {
    return false;
  }

  auto e14 = stateMachine.lastState();
  return e14->transition(stateMachine, s);
}
