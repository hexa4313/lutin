#ifndef E14_H
#define E14_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E14 : public State {
  public:
    E14(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif
