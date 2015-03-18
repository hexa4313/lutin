#ifndef E35_H
#define E35_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E35 : public State {
  public:
    E35() : State("E35") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
