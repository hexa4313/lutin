#ifndef E31_H
#define E31_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E31 : public State {
  public:
    E31(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif