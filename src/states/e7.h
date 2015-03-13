#ifndef E7_H
#define E7_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E7 : public State {
  public:
    E7(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif
