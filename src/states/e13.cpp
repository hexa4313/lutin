#include "e13.h"
#include "../state.h"

#include "../declaration/vardec.h"
#include "../declaration/vardeclist.h"
#include "e4.h"
#include "e12.h"
#include <boost/variant.hpp>

bool E13::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  stateMachine.popStates(1);
  auto symbols = stateMachine.popSymbols(1);

  auto varDec = std::make_shared<VarDec>(boost::get<std::string>(symbols[0]->getValue()));
  auto e4 = std::dynamic_pointer_cast<E4>(stateMachine.lastState());

  auto V = std::make_shared<VarDecList>();
  V->addVarDec(varDec);

  // reduction
  e4->transition(stateMachine, V);

  auto e12 = stateMachine.lastState();
  e12->transition(stateMachine, s);

  return true;

}
