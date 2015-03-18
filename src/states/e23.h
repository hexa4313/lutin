#ifndef E23_H
#define E23_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E23 : public State {
  public:
    E23(std::string name);
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif