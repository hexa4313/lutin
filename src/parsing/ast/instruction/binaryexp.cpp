#include "binaryexp.h"


std::vector<std::shared_ptr<Variable>> BinaryExp::getVarFromExpr(std::shared_ptr<Expression> expr) {
	std::vector<std::shared_ptr<Variable>> resultVect;

	if (expr->getType() == SymbolType::V) {
		std::shared_ptr<Variable> var = std::dynamic_pointer_cast<Variable> (expr);
		resultVect.push_back(var);
	}
	else if (expr->getType() == SymbolType::OP_A || expr->getType() == SymbolType::OP_M) {
		std::vector<std::shared_ptr<Variable>> tempLeftVect;
		std::vector<std::shared_ptr<Variable>> tempRightVect;
		std::shared_ptr<BinaryExp> binExp = std::dynamic_pointer_cast<BinaryExp> (expr);
		tempLeftVect = getVarFromExpr(binExp->m_left);
		tempRightVect = getVarFromExpr(binExp->m_right);

		//Insertion des deux vecteurs dans resultVect
	}
	/*else if (expr->getType() == SymbolType) {
		//Gestion des expressions de type parenthésées
	}*/
	
	return resultVect;
}
