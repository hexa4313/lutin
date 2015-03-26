#ifndef E2_H
#define E2_H

#include "state.h"

class E2 : public State {
  public:
    E2() : State("E2") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif