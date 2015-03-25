#ifndef E19_H
#define E19_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E19 : public State {
  public:
    E19() : State("E19") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
