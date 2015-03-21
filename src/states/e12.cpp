#include "e12.h"
#include "../state.h"

#include "e22.h"
#include "../declaration/vardeclist.h"
#include "../declaration/declarationlist.h"

bool E12::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  if(s->getType() == SymbolType::VG) {
    stateMachine.setState(s, std::make_shared<E22>());
  }
  else {
    stateMachine.popStates(2);
    auto symbols = stateMachine.popSymbols(2);

    auto v = std::dynamic_pointer_cast<VarDecList>(symbols[0]);

    auto e1 = stateMachine.lastState();

    // reduction
    e1->transition(stateMachine, v);

    auto e2 = stateMachine.lastState();
    e2->transition(stateMachine, s);
  }

  return true;

}
