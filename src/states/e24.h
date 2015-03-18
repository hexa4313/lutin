#ifndef E24_H
#define E24_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E24 : public State {
  public:
    E24() : State("E24") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif