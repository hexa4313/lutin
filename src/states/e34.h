#ifndef E34_H
#define E34_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E34 : public State {
  public:
    E34() : State("E34") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
