#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <stack>
#include <memory>
#include <vector>

#include "symbol.h"
#include "state.h"
#include "lexer.h"

class State;

class StateMachine {
	private:
		std::unique_ptr<Lexer> m_lexer;
		std::stack<std::shared_ptr<Symbol>> m_symbols;
		std::stack<std::shared_ptr<State>> m_states;
	public:
		StateMachine(std::string filepath) : m_lexer(new Lexer(filepath)) {}
		void read();

		std::vector<std::shared_ptr<Symbol>> popSymbols(int count);
		std::vector<std::shared_ptr<State>> popStates(int count);
		std::shared_ptr<State> lastState();
		std::shared_ptr<Symbol> lastSymbol();
		void pushSymbol(std::shared_ptr<Symbol> symbol);
		void pushState(std::shared_ptr<State> state);

		void setState(std::shared_ptr<Symbol> symbol, std::shared_ptr<State> state);
};

#endif
