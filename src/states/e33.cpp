#include "e33.h"
#include "../state.h"
#include "../declaration/vardec.h"
#include "../declaration/vardeclist.h"


bool E33::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto states = stateMachine.popStates(3);
  auto symbols = stateMachine.popSymbols(2);

  auto varDec = std::make_shared<VarDec>(boost::get<std::string>(symbols[0]->getValue()));
  auto v = std::dynamic_pointer_cast<VarDecList>(stateMachine.lastSymbol());
  v->addVarDec(varDec);
  stateMachine.lastState()->transition(stateMachine, stateMachine.lastSymbol());

  return true;

}
