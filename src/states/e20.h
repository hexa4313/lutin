#ifndef E20_H
#define E20_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E20 : public State {
  public:
    E20(std::string name);
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif