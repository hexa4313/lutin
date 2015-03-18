#include "e35.h"
#include "../state.h"

#include "../declaration/constdec.h"
#include "../declaration/constdeclist.h"
#include <boost/variant.hpp>

bool E35::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto states = stateMachine.popStates(3);
  auto symbols = stateMachine.popSymbols(3);

  auto id = boost::get<std::string>(symbols[2]->getValue());
  auto value = boost::get<int>(symbols[0]->getValue());
  auto constDec = std::make_shared<ConstDec>(id, value);

  auto c = std::dynamic_pointer_cast<ConstDecList>(stateMachine.lastSymbol());
  c->addConstDec(constDec);
  stateMachine.lastState()->transition(stateMachine, stateMachine.lastSymbol());
}
