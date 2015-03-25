#ifndef E29_H
#define E29_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E29 : public State {
  public:
    E29() : State("E29") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
