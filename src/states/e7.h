#ifndef E7_H
#define E7_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E7 : public State {
  public:
    E7() : State("E7") {};;
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
