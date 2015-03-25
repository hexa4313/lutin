#ifndef E36_H
#define E36_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E36 : public State {
  public:
    E36() : State("E36") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
