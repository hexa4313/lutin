#ifndef E33_H
#define E33_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E33 : public State {
  public:
    E33(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif