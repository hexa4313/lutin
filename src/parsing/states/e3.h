#ifndef E3_H
#define E3_H

#include "state.h"

class E3 : public State {
  public:
    E3() : State("E3") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif