#ifndef E8_H
#define E8_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E8 : public State {
  public:
    E8(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif
