#ifndef E0_H
#define E0_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E0 : public State {
  public:
    E0() : State("E0") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif