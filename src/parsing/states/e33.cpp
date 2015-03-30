#include "e33.h"
#include "../ast/declaration/vardeclist.h"


bool E33::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(3);
  auto symbols = stateMachine.popSymbols(3);

  auto varDec = std::make_shared<VarDec>(boost::get<std::string>(symbols[0]->getValue()));
  auto v = std::dynamic_pointer_cast<VarDecList>(symbols[2]);
  v->addVarDec(varDec);

  auto e4 = stateMachine.curState();

  // reduction
  if(!e4->transition(stateMachine, v)) {
    return false;
  }

  auto e12 = stateMachine.curState();
  return e12->transition(stateMachine, s);

}
