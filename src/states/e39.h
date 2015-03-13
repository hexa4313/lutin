#ifndef E39_H
#define E39_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E39 : public State {
  public:
    E39(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif