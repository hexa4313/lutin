#include "binaryexp.h"


std::vector<std::shared_ptr<Variable>> BinaryExp::getAllVar(){
	std::vector<std::shared_ptr<Variable>> varExp;

	while ((m_left.getType() != SymbolType::E_VAL || m_left.getType() != SymbolType::E_CNUM) && varExp.find(varExp.begin(), varExp.end(), m_left) == varExp.end()) 
	{
		m_left.getAllVar();
	};

	while ((m_right.getType() != SymbolType::E_VAL || m_right.getType() != SymbolType::E_CNUM) && varExp.find(varExp.begin(), varExp.end(), m_right) == varExp.end())
	{
		m_right.getAllVar();
	};

	if (m_left.getType() == SymbolType::E_VAL){
		varExp.push_back(m_left);
	}
	
	if (m_right.getType() == SymbolType::E_VAL){
		varExp.push_back(m_right);
	}

	return varExp;
}
