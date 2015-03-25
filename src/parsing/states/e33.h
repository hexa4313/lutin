#ifndef E33_H
#define E33_H

#include "state.h"

class E33 : public State {
  public:
    E33() : State("E33") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
