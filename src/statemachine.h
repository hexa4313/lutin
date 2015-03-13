#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "symbol.h"
#include "state.h"
#include "lexer.h"
#include <stack>
#include <memory>

class StateMachine {
	private:
		std::unique_ptr<Lexer> m_lexer;
		std::stack<std::shared_ptr<Symbol>> m_symbols;
		std::stack<std::shared_ptr<State>> m_states;
		void read();
	public:
		StateMachine(std::string filepath) : m_lexer(new Lexer(filepath)) {}
		std::shared_ptr<Symbol> pop_symbol();
		std::shared_ptr<State> pop_state();
		void setState(Symbol * symbol, State * state);
};

#endif
