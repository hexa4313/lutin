#ifndef E11_H
#define E11_H

#include "state.h"

class E11 : public State {
  public:
    E11() : State("E11") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
