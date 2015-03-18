#ifndef E13_H
#define E13_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E13 : public State {
  public:
    E13() : State("E13") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
