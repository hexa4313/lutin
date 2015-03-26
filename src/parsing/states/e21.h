#ifndef E21_H
#define E21_H

#include "state.h"

class E21 : public State {
  public:
    E21() : State("E21") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif