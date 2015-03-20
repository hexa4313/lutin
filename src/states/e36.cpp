#include "e36.h"
#include "../state.h"
#include "e25.h"
#include "e26.h"
#include "e27.h"
#include "e28.h"
#include "e29.h"
#include "e30.h"
#include "e9.h"
#include "../instruction/expression.h"
#include "../instruction"


bool E36::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto symbols = stateMachine.popSymbols(3);
  auto states = stateMachine.popStates(3);

  auto expL = std::dynamic_pointer_cast<Expression>(symbols[2]);
  auto expR = std::dynamic_pointer_cast<Expression>(symbols[0]);
  auto expmul =  std::dynamic_pointer_cast<Expression>(symbols[1]); // really an ExprMul or ExprDiv
  expmul->setExpressions(expL, expR);

  stateMachine.setState(expmul, std::make_shared<E17>());

  switch(s->getType()) {
    case SymbolType::MUL :
      stateMachine.setState(s, std::make_shared<E25>());
      return true;
    case SymbolType::DIV :
      stateMachine.setState(s, std::make_shared<E26>());
      return true;
    case SymbolType::SUB :
      stateMachine.setState(s, std::make_shared<E27>());
      return true;
    case SymbolType::ADD :
      stateMachine.setState(s, std::make_shared<E28>());
      return true;
    case SymbolType::OP_M :
      stateMachine.setState(s, std::make_shared<E29>());
      return true;
    case SymbolType::OP_A :
      stateMachine.setState(s, std::make_shared<E30>());
      return true;
    case SymbolType::E : 
      stateMachine.setState(s, std::make_shared<E9>());
      return true;
    default :
      return false;
  }
}
