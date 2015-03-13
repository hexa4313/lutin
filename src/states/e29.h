#ifndef E29_H
#define E29_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E29 : public State {
  public:
    E29(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif
