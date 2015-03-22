#include "e14.h"
#include "../state.h"
#include "e23.h"
#include "../declaration/constdeclist.h"
#include "../declaration/declarationlist.h"

bool E14::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  if(s->getType() == SymbolType::VG) {
    stateMachine.setState(s, std::make_shared<E23>());
  }
  else {
    stateMachine.popStates(2);
    auto symbols = stateMachine.popSymbols(2);

    auto c = std::dynamic_pointer_cast<ConstDecList>(symbols[0]);

    auto e1 = stateMachine.lastState();

    // reduction
    e1->transition(stateMachine, c);

    auto e2 = stateMachine.lastState();
    e2->transition(stateMachine, s);
  }

  return true;
}
