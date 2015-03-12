#ifndef E3_H
#define E3_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E3 : public State {
  public:
    E3(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif