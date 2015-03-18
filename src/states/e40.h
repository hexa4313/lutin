#ifndef E40_H
#define E40_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E40 : public State {
  public:
    E40() : State("E40") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
