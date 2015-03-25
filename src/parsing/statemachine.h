#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <memory>
#include <stack>
#include <vector>
#include "lexer.h"
#include "ast/program.h"

class State;

class StateMachine {
	private:
    Lexer m_lexer;
    std::shared_ptr<Program> m_program;
		std::stack<std::shared_ptr<Symbol>> m_symbols;
		std::stack<std::shared_ptr<State>> m_states;
	public:
		StateMachine(std::string filepath) : m_lexer(filepath) {}
		std::shared_ptr<Program> read();

		std::vector<std::shared_ptr<Symbol>> popSymbols(int count);
		void popStates(int count);
		std::shared_ptr<State> lastState();
		std::shared_ptr<Symbol> lastSymbol();

		void setState(std::shared_ptr<Symbol> symbol, std::shared_ptr<State> state);
    void accept(std::shared_ptr<Program> p) { m_program = p; }
};

#endif
