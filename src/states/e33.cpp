#include "e33.h"
#include "../declaration/vardec.h"
#include "../declaration/vardeclist.h"


bool E33::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(3);
  auto symbols = stateMachine.popSymbols(3);

  auto varDec = std::make_shared<VarDec>(boost::get<std::string>(symbols[0]->getValue()));
  auto v = std::dynamic_pointer_cast<VarDecList>(symbols[2]);
  v->addVarDec(varDec);

  auto e4 = stateMachine.lastState();

  // reduction
  e4->transition(stateMachine, v);

  auto e12 = stateMachine.lastState();
  e12->transition(stateMachine, s);

  return true;

}
