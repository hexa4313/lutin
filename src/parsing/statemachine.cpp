#include "statemachine.h"
#include "states/e0.h"
#include "states/e1.h"
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
    //std::cout << "Symbol lu " << *symbol << std::endl;
    auto lastState = m_states.top();
    //std::cout << "Etat traite " << lastState -> name() << std::endl;
    if(symbol->getType() == SymbolType::UNKNOWN)
    {
    	std::cerr << "Erreur lexicale caractere " << std::dynamic_pointer_cast<Unknown>(symbol)->getChar() << std::endl;
    }
    else if(!lastState->transition(*this, symbol)) 
    {
        lastState = m_states.top();
    	bool syntaxError = checkSyntax(lastState, symbol);
	if (!syntaxError) 
    	{
		std::cerr << "Error in transition!" << std::endl;
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

bool StateMachine::checkSyntax(std::shared_ptr<State> st, std::shared_ptr<Symbol> s ) {
  std::string stName = st->name();
  //std::cout << "Check State syntax error : " << stName << std::endl;
  if (stName == "E22" || stName == "E23"){
	std::cerr << "Erreur syntaxique : symbole , attendu" << std::endl;  	
	st->transition(*this, s);
	return true;
  }
  if (stName == "E2" || stName == "E8"){
	// Non fonctionnel encore -- En attente de la récupération de fin de ligne
	std::cerr << "Erreur syntaxique : symbole ; attendu" << std::endl;  	
	st->transition(*this, std::make_shared<Symbol>(Symbol(SymbolType::PV)));
	return true;
  }
  if (stName == "E41"){
	std::cerr << "Erreur syntaxique : opérateur :=  attendu" << std::endl;  	
	st->transition(*this, s);
	return true;	
  }
  return false;
}
