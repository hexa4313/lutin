#ifndef E12_H
#define E12_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E12 : public State {
  public:
    E12(std::string name);
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
