#include "e36.h"

#include "e17.h"
#include "e25.h"
#include "e26.h"
#include "e27.h"
#include "e28.h"
#include "e29.h"
#include "e30.h"
#include "e9.h"
#include "../instruction/expression.h"
#include "../instruction/binaryexp.h"


bool E36::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto symbols = stateMachine.popSymbols(3);
  stateMachine.popStates(3);

  auto expL = std::dynamic_pointer_cast<Expression>(symbols[2]);
  auto expR = std::dynamic_pointer_cast<Expression>(symbols[0]);
  auto expmul =  std::dynamic_pointer_cast<BinaryExp>(symbols[1]);
  expmul->setExpressions(expL, expR);

  auto e9 = stateMachine.lastState();

  //reduction (car priorité mult)
  e9->transition(stateMachine, expmul);

  auto e17 = stateMachine.lastState();
  e17->transition(stateMachine, s);

  return true;
}
