#ifndef E12_H
#define E12_H

#include "state.h"

class E12 : public State {
  public:
    E12() : State("E12") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
