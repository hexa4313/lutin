#ifndef E19_H
#define E19_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E19 : public State {
  public:
    E19(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif
