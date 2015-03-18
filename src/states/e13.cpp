#include "e13.h"
#include "../state.h"

#include "../declaration/vardec.h"
#include "../declaration/vardeclist.h"
#include <boost/variant.hpp>

bool E13::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto states = stateMachine.popStates(1);
  auto symbols = stateMachine.popSymbols(1);

  auto varDec = std::make_shared<VarDec>(boost::get<std::string>(symbols[0]->getValue()));
  auto v = std::dynamic_pointer_cast<VarDecList>(stateMachine.lastSymbol());
  v->addVarDec(varDec);
  stateMachine.lastState()->transition(stateMachine, stateMachine.lastSymbol());

}
