#include "statemachine.h"
#include "states/e0.h"
#include  "ast/unknown.h"
#include <boost/lexical_cast.hpp>

#include <iostream>

std::shared_ptr<Program> StateMachine::read() {

  auto e0 = std::make_shared<E0>();
  m_states.push(e0);
  e0->transition(*this, std::make_shared<DeclarationList>());

  std::shared_ptr<Symbol> symbol;

  do {
    symbol = m_lexer.getSymbol();
    auto curState = m_states.top();
    if(symbol->getType() == SymbolType::UNKNOWN) {
      auto unknown = std::dynamic_pointer_cast<Unknown>(symbol);
    	std::cerr << "Erreur lexicale (" << symbol->getLine() << ":";
      std::cerr << symbol->getCol() << ") caractere ";
      std::cerr << unknown->getChar() << std::endl;
    }
    else if(!curState->transition(*this, symbol)) {
      std::cerr << "Erreur syntaxique. Symbole non attendu: " << *symbol << std::endl;
      return nullptr;
    }
    m_lastSymbol = symbol;
    m_lexer.shift();

  } while(symbol->getType() != SymbolType::END);

  return m_program;
}

void StateMachine::setState(std::shared_ptr<Symbol> symbol, std::shared_ptr<State> state) {
  m_symbols.push(symbol);
  m_states.push(state);
}

std::vector<std::shared_ptr<Symbol>> StateMachine::popSymbols(int count) {
  std::vector<std::shared_ptr<Symbol>> symbols;
  for(int i = 0; i < count; i++) {
    symbols.push_back(m_symbols.top());
    m_symbols.pop();
  }
  return symbols;
}

void StateMachine::popStates(int count) {
  for(int i = 0; i < count; i++) {
    m_states.pop();
  }
}

std::shared_ptr<State> StateMachine::curState() {
  return m_states.top();
}