#include "../state.h"
#include "e1.h"
#include "e2.h"
#include "e3.h"
#include "e4.h"
#include "e5.h"
#include "e9.h"
#include "e10.h"
#include "e11.h"


#include "../declaration/vardeclist.h"
#include "../declaration/constdeclist.h"
#include <memory>



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
    // implicite end of declarations, jump to instructions
    case SymbolType::R : {
	  auto instList = std::make_shared<InstructionList>();
      stateMachine.pushSymbol(instList);
      stateMachine.pushState(std::make_shared<E3>());
      stateMachine.setState(s, std::make_shared<E10>());
      break;
    }
    case SymbolType::W : {
	  auto instList = std::make_shared<InstructionList>();
      stateMachine.pushSymbol(instList);
      stateMachine.pushState(std::make_shared<E3>());
      stateMachine.setState(s, std::make_shared<E9>());
      break;
    }
    case SymbolType::ID : {
	  auto instList = std::make_shared<InstructionList>();
      stateMachine.pushSymbol(instList);
      stateMachine.pushState(std::make_shared<E3>());
      stateMachine.setState(s, std::make_shared<E11>());
      break;
    }
    //?? $ case
    default :
      // TODO : gerer les erreurs
      break;
  }
  return false;
}
