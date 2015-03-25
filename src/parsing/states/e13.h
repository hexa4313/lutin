#ifndef E13_H
#define E13_H

#include "state.h"

class E13 : public State {
  public:
    E13() : State("E13") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
