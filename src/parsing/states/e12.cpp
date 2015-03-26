#include "e12.h"

#include "e22.h"
#include "../ast/declaration/vardeclist.h"

bool E12::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  if(s->getType() == SymbolType::VG) {
    stateMachine.setState(s, std::make_shared<E22>());

    return true;
  }
  else {
    stateMachine.popStates(2);
    auto symbols = stateMachine.popSymbols(2);

    auto v = std::dynamic_pointer_cast<VarDecList>(symbols[0]);

    auto e1 = stateMachine.lastState();

    // reduction
    if(!e1->transition(stateMachine, v)) {
      return false;
    }

    auto e2 = stateMachine.lastState();
    return e2->transition(stateMachine, s);
  }

}
