#ifndef E32_H
#define E32_H

#include "state.h"

class E32 : public State {
  public:
    E32() : State("E32") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
