#ifndef E38_H
#define E38_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E38 : public State {
  public:
    E38() : State("E38") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
