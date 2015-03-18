#include "e14.h"
#include "../state.h"

E14::E14 (std::string name) : State(name)
{

}
 
bool E14::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  if(s->getType() == SymbolType::VG) {
    stateMachine.setState(s, new E23);
  }
  else {
    stateMachine.popStates(2);
    stateMachine.popSymbols(2);
    stateMachine.lastState()->transition(stateMachine, s);
  }
}
