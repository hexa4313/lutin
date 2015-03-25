#include "statemachine.h"
#include "states/e0.h"
#include "ast/declaration/declarationlist.h"

std::shared_ptr<Program> StateMachine::read() {

  auto e0 = std::make_shared<E0>();
  m_states.push(e0);
  e0->transition(*this, std::make_shared<DeclarationList>());

  std::shared_ptr<Symbol> symbol;

  do {

    symbol = m_lexer.getSymbol();
    auto lastState = m_states.top();

    if(!lastState->transition(*this, symbol)) {
      std::cout << "Error in transition!" << std::endl;
      return nullptr;
    }
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

std::shared_ptr<State> StateMachine::lastState() {
  return m_states.top();
}

std::shared_ptr<Symbol> StateMachine::lastSymbol() {
  return m_symbols.top();
}