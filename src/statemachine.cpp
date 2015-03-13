#include <iostream>
#include "statemachine.h"

void StateMachine::read() {
  std::shared_ptr<Symbol> symbol = m_lexer->getSymbol();
  while(symbol->getType() != SymbolType::$) {

    std::shared_ptr<State> lastState = m_states.top();
    if(!lastState->transition(*this, symbol.get())) {
      std::cout << "Error in transition!";
    }

    symbol = m_lexer->getSymbol();
  }
}