#ifndef E21_H
#define E21_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E21 : public State {
  public:
    E21(std::string name);
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif