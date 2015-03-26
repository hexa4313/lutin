#ifndef E23_H
#define E23_H

#include "state.h"

class E23 : public State {
  public:
    E23() : State("E23") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif