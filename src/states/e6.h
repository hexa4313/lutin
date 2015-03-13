#ifndef E6_H
#define E6_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E6 : public State {
  public:
    E6(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif
