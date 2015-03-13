#ifndef E35_H
#define E35_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E35 : public State {
  public:
    E35(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif