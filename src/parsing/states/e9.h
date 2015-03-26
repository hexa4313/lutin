#ifndef E9_H
#define E9_H

#include "state.h"

class E9 : public State {
  public:
    E9() : State("E9") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
