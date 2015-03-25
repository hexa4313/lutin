#ifndef E27_H
#define E27_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E27 : public State {
  public:
    E27() : State("E27") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
