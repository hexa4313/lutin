#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "symbol.h"
#include "state.h"

class StateMachine {
	class State * s;
  	public:
		void setState(Symbol * symbol, State * state);
	private:
    		void read();
};

#endif
