#ifndef E1_H
#define E1_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E1 : public State {
  public:
    E1() : State("E1") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif