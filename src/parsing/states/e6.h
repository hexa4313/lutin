//
// Created by edouard on 13/03/15.
//

#ifndef _LUTIN_E6_H_
#define _LUTIN_E6_H_

#include <string>
#include "../state.h"
#include "../statemachine.h"
#include "../symbol.h"

class E6 : public State {
public:
  E6() : State("E6") {};
  bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s);
};

#endif //_LUTIN_E6_H_