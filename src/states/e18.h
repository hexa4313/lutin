#ifndef E18_H
#define E18_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E18 : public State {
  public:
    E18(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif
