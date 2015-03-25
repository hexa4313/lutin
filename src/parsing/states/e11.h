#ifndef E11_H
#define E11_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E11 : public State {
  public:
    E11() : State("E11") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
