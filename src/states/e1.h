#ifndef E1_H
#define E1_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E1 : public State {
  public:
    E1(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif