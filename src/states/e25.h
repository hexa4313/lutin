#ifndef E25_H
#define E25_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"

class E25 : public State {
  public:
    E25(std::string name);
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
