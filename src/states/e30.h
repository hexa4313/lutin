#ifndef E30_H
#define E30_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E30 : public State {
  public:
    E30() : State("E30") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
