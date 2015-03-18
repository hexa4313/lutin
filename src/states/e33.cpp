#include "e33.h"
#include "../state.h"

E33::E33 (std::string name) : State(name)
{

}

bool E33::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto states = stateMachine.popStates(3);
  auto symbols = stateMachine.popSymbols(3);

  auto varDec = std::make_shared(new VarDec(boost::get<std::string>(symbols[0]->getValue())));
  auto v = std::dynamic_pointer_cast<VarDecList>(stateMachine.lastSymbol());
  v->addVarDec(varDec);
  stateMachine.lastState()->transition(stateMachine, stateMachine.lastSymbol());

}
