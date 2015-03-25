#ifndef E10_H
#define E10_H

#include "state.h"

class E10 : public State {
  public:
    E10() : State("E10") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
