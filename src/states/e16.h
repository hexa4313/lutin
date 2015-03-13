#ifndef E16_H
#define E16_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E16 : public State {
  public:
    E16(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif
