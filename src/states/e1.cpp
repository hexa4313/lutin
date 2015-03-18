#include "e1.h"
#include "../state.h"

#include "../declaration/vardeclist.h"
#include "../declaration/constdeclist.h"

#include "e2.h"
#include "e3.h"
#include "e4.h"
#include "e5.h"


bool E1::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::D :
      stateMachine.setState(s, std::make_shared<E2>());
      break;
    case SymbolType::IL :
      stateMachine.setState(s, std::make_shared<E3>());
      break;
    case SymbolType::VAR : {
      stateMachine.setState(s, std::make_shared<E4>());
      auto declVar = std::make_shared<VarDecList>();
      stateMachine.pushSymbol(declVar);
      break;
    }
    case SymbolType::CST : {
      stateMachine.setState(s, std::make_shared<E5>());
      auto declConst = std::make_shared<ConstDecList>();
      stateMachine.pushSymbol(declConst);
      break;
    }
    default :
      // TODO : gerer les erreurs
      break;
  }
  return false;
}
