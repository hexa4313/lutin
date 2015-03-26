#ifndef E8_H
#define E8_H

#include "state.h"

class E8 : public State {
  public:
    E8() : State("E8") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
