#ifndef E16_H
#define E16_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E16 : public State {
  public:
    E16() : State("E16") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
