#include "e37.h"
#include "e25.h"
#include "e26.h"
#include "e29.h"
#include "e30.h"
#include "../instruction/binaryexp.h"
#include "e27.h"
#include "e28.h"

bool E37::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

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
    default :

      auto symbols = stateMachine.popSymbols(3);
      stateMachine.popStates(3);

      auto expL = std::dynamic_pointer_cast<Expression>(symbols[2]);
      auto expR = std::dynamic_pointer_cast<Expression>(symbols[0]);
      auto expadd =  std::dynamic_pointer_cast<BinaryExp>(symbols[1]);
      expadd->setExpressions(expL, expR);

      auto e9 = stateMachine.lastState();

      //reduction
      e9->transition(stateMachine, expadd);

      auto e17 = stateMachine.lastState();
      e17->transition(stateMachine, s);

      return true;
  }
}
