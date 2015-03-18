#ifndef E15_H
#define E15_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E15 : public State {
  public:
    E15() : State("E15") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
