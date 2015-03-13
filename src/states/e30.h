#ifndef E30_H
#define E30_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E30 : public State {
  public:
    E30(std::string name);
    bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif
