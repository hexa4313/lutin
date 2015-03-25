#ifndef E17_H
#define E17_H

#include "state.h"

class E17 : public State {
  public:
    E17() : State("E17") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
