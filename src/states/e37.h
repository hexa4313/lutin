#ifndef E37_H
#define E37_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E37 : public State {
  public:
    E37(std::string name);
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif