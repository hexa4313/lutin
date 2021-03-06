#ifndef E5_H
#define E5_H

#include "state.h"

class E5 : public State {
  public:
    E5() : State("E5") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
