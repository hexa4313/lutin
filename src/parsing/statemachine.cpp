#include "statemachine.h"
#include "states/e0.h"
#include "ast/declaration/declarationlist.h"
#include  "ast/symboltype.h"
#include  "ast/unknown.h"
#include <string>
#include <boost/lexical_cast.hpp>

std::shared_ptr<Program> StateMachine::read() {

  auto e0 = std::make_shared<E0>();
  m_states.push(e0);
  e0->transition(*this, std::make_shared<DeclarationList>());

  std::shared_ptr<Symbol> symbol;

  do {

    symbol = m_lexer.getSymbol();
    //std::cout << "Symbol lu " << symbol->getValue() << std::endl;
    auto lastState = m_states.top();

	if(symbol->getType() == SymbolType::UNKNOWN)
	{
	  std::cout << "Erreur lexicale caractere " << std::dynamic_pointer_cast<Unknown>(symbol)->getChar() << std::endl;
	}
   
    else if(!lastState->transition(*this, symbol)) {
      bool syntaxError = checkSyntax(lastState);
		if (!syntaxError) {
			//std::cout << "Error in transition!" << std::endl;
				return nullptr;
		} 
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

bool StateMachine::checkSyntax(std::shared_ptr<State> st) {
  std::string stName = st->name();
 std::cout << stName << std::endl;
  if (stName == "E12" || stName == "E14"){
  	std::cout << "Erreur syntaxique (:) symbole , probablement attendu" << std::endl;  
	st->transition(*this, std::make_shared<Symbol>(Symbol(SymbolType::VG)));
	return true;
  }
  if (stName == "E2" || stName == "E8"){
	std::cout << "Erreur syntaxique (:) symbole ; attendu" << std::endl;  	
	st->transition(*this, std::make_shared<Symbol>(Symbol(SymbolType::PV)));
	return true;
  }
  if (stName == "E11"){
	std::cout << "Erreur syntaxique (:) opérateur :=  attendu" << std::endl;  	
	st->transition(*this, std::make_shared<Symbol>(Symbol(SymbolType::AFF)));
	return true;	
  }
  return false;
}
