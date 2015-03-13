#ifndef E28_H
#define E28_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E28 : public State {
  public:
    E28(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif
