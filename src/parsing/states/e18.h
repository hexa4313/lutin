#ifndef E18_H
#define E18_H

#include "state.h"

class E18 : public State {
  public:
    E18() : State("E18") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
