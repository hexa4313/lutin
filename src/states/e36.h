#ifndef E36_H
#define E36_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E36 : public State {
  public:
    E36(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif