#ifndef E4_H
#define E4_H

#include "state.h"

class E4 : public State {
  public:
    E4() : State("E4") { };
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
