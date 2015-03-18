#ifndef E15_H
#define E15_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E15 : public State {
  public:
    E15(std::string name);
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
