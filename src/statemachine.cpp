#include <iostream>
#include <vector>
#include "statemachine.h"

#include "declaration/declarationlist.h"
#include "states/e0.h"

void StateMachine::read() {

  auto e0 = std::make_shared<E0>();
  m_states.push_back(e0);
  e0->transition(*this, std::make_shared<DeclarationList>());

  std::shared_ptr<Symbol> symbol;

  do {

    symbol = m_lexer->getSymbol();

    std::shared_ptr<State> lastState = m_states.back();
    if(!lastState->transition(*this, symbol)) {
      std::cout << "Error in transition!" << std::endl;
    }
    m_lexer->shift();

  } while(symbol->getType() != SymbolType::$);

  std::cout << *m_symbols.back() << std::endl;
}

void StateMachine::setState(std::shared_ptr<Symbol> symbol, std::shared_ptr<State> state) {
  m_symbols.push_back(symbol);
  m_states.push_back(state);
}

std::vector<std::shared_ptr<Symbol>> StateMachine::popSymbols(int count) {
  std::vector<std::shared_ptr<Symbol>> symbols;
  for(int i = 0; i < count; i++) {
    symbols.push_back(m_symbols.back());
    m_symbols.pop_back();
  }
  return symbols;
}

void StateMachine::popStates(int count) {
  for(int i = 0; i < count; i++) {
    m_states.pop_back();
  }
}

std::shared_ptr<State> StateMachine::lastState() {
  return m_states.back();
}

std::shared_ptr<Symbol> StateMachine::lastSymbol() {
  return m_symbols.back();
}

void StateMachine::pushSymbol(std::shared_ptr<Symbol> symbol) {
  m_symbols.push_back(symbol);
}

void StateMachine::pushState(std::shared_ptr<State> state) {
  m_states.push_back(state);
}