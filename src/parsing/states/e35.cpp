#include "e35.h"

#include "../ast/declaration/constdeclist.h"
#include "e5.h"

bool E35::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(3);
  auto symbols = stateMachine.popSymbols(3);

  auto id = boost::get<std::string>(symbols[2]->getValue());
  auto value = boost::get<int>(symbols[0]->getValue());
  auto constDec = std::make_shared<ConstDec>(id, value);

  auto C = std::make_shared<ConstDecList>();
  C->addConstDec(constDec);

  // reduction
  auto e5 = std::dynamic_pointer_cast<E5>(stateMachine.curState());
  if(!e5->transition(stateMachine, C)) {
    return false;
  }

  auto e14 = stateMachine.curState();
  return e14->transition(stateMachine, s);
}
