#ifndef E5_H
#define E5_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E5 : public State {
  public:
    E5(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif
