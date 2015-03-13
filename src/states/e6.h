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
  E6(std::string name);
  bool transition(StateMachine & stateMachine, Symbol * s);
};

#endif //_LUTIN_E6_H_