#ifndef E32_H
#define E32_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E32 : public State {
  public:
    E32(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif