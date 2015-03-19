#include <iostream>
#include <vector>
#include "statemachine.h"

#include "declaration/declarationlist.h"
#include "states/e0.h"
#include "states/e1.h"

void StateMachine::read() {

  m_states.push(std::make_shared<E0>());
  setState(std::make_shared<DeclarationList>(), std::make_shared<E1>());

  std::shared_ptr<Symbol> symbol = m_lexer->getSymbol();
  while(symbol->getType() != SymbolType::$) {

    std::shared_ptr<State> lastState = m_states.top();
    if(!lastState->transition(*this, symbol)) {
      std::cout << "Error in transition!" << std::endl;
    }

    m_lexer->shift();
    symbol = m_lexer->getSymbol();
  }
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

std::vector<std::shared_ptr<State>> StateMachine::popStates(int count) {
  std::vector<std::shared_ptr<State>> states;
  for(int i = 0; i < count; i++) {
    states.push_back(m_states.top());
    m_states.pop();
  }
  return states;
}

std::shared_ptr<State> StateMachine::lastState() {
  return m_states.top();
}

std::shared_ptr<Symbol> StateMachine::lastSymbol() {
  return m_symbols.top();
}

void StateMachine::pushSymbol(std::shared_ptr<Symbol> symbol) {
  m_symbols.push(symbol);
}

void StateMachine::pushState(std::shared_ptr<State> state) {
  m_states.push(state);
}