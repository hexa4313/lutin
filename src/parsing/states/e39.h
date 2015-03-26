#ifndef E39_H
#define E39_H

#include "state.h"

class E39 : public State {
  public:
    E39() : State("E39") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
