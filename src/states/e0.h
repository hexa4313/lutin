#ifndef E0_H
#define E0_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E0 : public State {
  public:
    E0(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif