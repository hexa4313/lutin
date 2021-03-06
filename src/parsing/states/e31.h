#ifndef E31_H
#define E31_H

#include "state.h"

class E31 : public State {
  public:
    E31() : State("E31") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
