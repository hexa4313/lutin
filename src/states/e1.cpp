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
#include "../instruction/instructionlist.h"


bool E1::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::D :
      stateMachine.setState(s, std::make_shared<E2>());
      return true;
    case SymbolType::IL :
      stateMachine.setState(s, std::make_shared<E3>());
      return true;
    case SymbolType::VAR : {
      stateMachine.setState(s, std::make_shared<E4>());
      auto declVar = std::make_shared<VarDecList>();
      stateMachine.pushSymbol(declVar);
      return true;
    }
    case SymbolType::CST : {
      stateMachine.setState(s, std::make_shared<E5>());
      auto declConst = std::make_shared<ConstDecList>();
      stateMachine.pushSymbol(declConst);
      return true;
    }
    // implicit end of declarations, jump to instructions
    case SymbolType::R : {
      auto instList = std::make_shared<InstructionList>();
      stateMachine.pushSymbol(instList);
      stateMachine.pushState(std::make_shared<E3>());
      stateMachine.setState(s, std::make_shared<E10>());
      return true;
    }
    case SymbolType::W : {
      auto instList = std::make_shared<InstructionList>();
      stateMachine.pushSymbol(instList);
      stateMachine.pushState(std::make_shared<E3>());
      stateMachine.setState(s, std::make_shared<E9>());
      return true;
    }
    case SymbolType::ID : {
      auto instList = std::make_shared<InstructionList>();
      stateMachine.pushSymbol(instList);
      stateMachine.pushState(std::make_shared<E3>());
      stateMachine.setState(s, std::make_shared<E11>());
      return true;
    }
    default :
      return false;
  }
}
