#ifndef E4_H
#define E4_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E4 : public State {
  public:
    E4(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif
