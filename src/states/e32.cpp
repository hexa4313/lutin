#include "e32.h"
#include "e25.h"
#include "e26.h"
#include "e27.h"
#include "e28.h"
#include "e29.h"
#include "e30.h"
#include "../instruction/assign.h"


bool E32::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

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
      stateMachine.popStates(3);
      auto symbols = stateMachine.popSymbols(3);

      auto id = boost::get<std::string>(symbols[2]->getValue());
      auto E = std::dynamic_pointer_cast<Expression>(symbols[0]);
      auto I = std::make_shared<Assign>(id, E);

      //reduction
      auto e3 = stateMachine.lastState();
      e3->transition(stateMachine, I);

      auto e1 = stateMachine.lastState();
      e1->transition(stateMachine, s);

      return true;
  }
}
