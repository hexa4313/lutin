#ifndef E5_H
#define E5_H

#include <string>
#include "../state.h"
#include "../symbol.h"
#include "../statemachine.h"
#include "../declaration/constdec.h"
#include "../declaration/constdeclist.h"

class E5 : public State {
  public:
    E5() : State("E5") {};
    bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif
