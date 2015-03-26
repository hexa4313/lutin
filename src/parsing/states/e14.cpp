#include "e14.h"
#include "e23.h"
#include "../ast/declaration/constdeclist.h"

bool E14::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  if(s->getType() == SymbolType::VG) {
    stateMachine.setState(s, std::make_shared<E23>());
    return true;
  }
  else {
    stateMachine.popStates(2);
    auto symbols = stateMachine.popSymbols(2);

    auto c = std::dynamic_pointer_cast<ConstDecList>(symbols[0]);

    auto e1 = stateMachine.lastState();

    // reduction
    if(!e1->transition(stateMachine, c)) {
      return false;
    }

    auto e2 = stateMachine.lastState();
    return e2->transition(stateMachine, s);
  }
}
