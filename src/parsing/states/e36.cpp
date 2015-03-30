#include "e36.h"

#include "../ast/expression/binaryexp.h"


bool E36::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto symbols = stateMachine.popSymbols(3);
  stateMachine.popStates(3);

  auto expL = std::dynamic_pointer_cast<Expression>(symbols[2]);
  auto expR = std::dynamic_pointer_cast<Expression>(symbols[0]);
  auto expmul =  std::dynamic_pointer_cast<BinaryExp>(symbols[1]);
  expmul->setExpressions(expL, expR);

  auto e9 = stateMachine.curState();

  //reduction (car priorité mult)
  if(!e9->transition(stateMachine, expmul)) {
    return false;
  }

  auto e17 = stateMachine.curState();
  return e17->transition(stateMachine, s);
}
