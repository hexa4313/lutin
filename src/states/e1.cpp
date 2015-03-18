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
      stateMachine.setState(s, new E2);
      break;
    case SymbolType::IL :
      stateMachine.setState(s, new E3);
      break;
    case SymbolType::VAR :
      stateMachine.setState(s, new E4);
      auto declVar = std::make_shared(new VarDecList);
      stateMachine.pushSymbol(declVar);
      break;
    case SymbolType::CST :
      stateMachine.setState(s, new E5);
      auto declConst = std::make_shared(new ConstDecList);
      stateMachine.pushSymbol(declConst);
      break;
    default :
      // TODO : gerer les erreurs
      break;
  }
  return false;
}
