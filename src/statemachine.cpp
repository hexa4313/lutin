#include <iostream>
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
      std::cout << "Error in transition!";
    }

    symbol = m_lexer->getSymbol();
  }
}

void StateMachine::setState(std::shared_ptr<Symbol> symbol, std::shared_ptr<State> state) {
  m_symbols.push(symbol);
  m_states.push(state);
}