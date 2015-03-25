#ifndef E14_H
#define E14_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E14 : public State {
  public:
    E14() : State("E14") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
