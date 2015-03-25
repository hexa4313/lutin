#ifndef E35_H
#define E35_H

#include "state.h"

class E35 : public State {
  public:
    E35() : State("E35") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
