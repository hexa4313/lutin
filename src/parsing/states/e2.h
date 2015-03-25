#ifndef E2_H
#define E2_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E2 : public State {
  public:
    E2() : State("E2") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif