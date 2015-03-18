#ifndef E10_H
#define E10_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E10 : public State {
  public:
    E10() : State("E10") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
