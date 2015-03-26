#ifndef E20_H
#define E20_H

#include "state.h"

class E20 : public State {
  public:
    E20() : State("E20") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif