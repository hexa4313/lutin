#ifndef E40_H
#define E40_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E40 : public State {
  public:
    E40(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif