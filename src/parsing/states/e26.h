#ifndef E26_H
#define E26_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E26 : public State {
  public:
    E26() : State("E26") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
