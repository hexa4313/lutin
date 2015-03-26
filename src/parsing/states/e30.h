#ifndef E30_H
#define E30_H

#include "state.h"

class E30 : public State {
  public:
    E30() : State("E30") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
