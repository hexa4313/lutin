#ifndef E34_H
#define E34_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E34 : public State {
  public:
    E34(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif