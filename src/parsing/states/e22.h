#ifndef E22_H
#define E22_H

#include "state.h"

class E22 : public State {
  public:
    E22() : State("E22") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif