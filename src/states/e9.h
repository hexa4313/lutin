#ifndef E9_H
#define E9_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E9 : public State {
  public:
    E9(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif
