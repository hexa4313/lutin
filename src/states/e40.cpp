#include "e40.h"
#include "../state.h"


bool E40::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto states = stateMachine.popStates(5);
  auto symbols = stateMachine.popSymbols(5);

  auto id = boost::get<std::string>(symbols[2]->getValue());
  auto value = boost::get<int>(symbols[0]->getValue());
  auto constDec = std::make_shared(new ConstDec(id, value));

  auto c = std::dynamic_pointer_cast<ConstDecList>(stateMachine.lastSymbol());
  c->addConstDec(constDec);
  stateMachine.lastState()->transition(stateMachine, stateMachine.lastSymbol());
}
