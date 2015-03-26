#ifndef E28_H
#define E28_H

#include "state.h"

class E28 : public State {
  public:
    E28() : State("E28") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
