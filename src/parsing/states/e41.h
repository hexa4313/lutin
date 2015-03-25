#ifndef E41_H
#define E41_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E41 : public State {
  public:
    E41() : State("E41") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
