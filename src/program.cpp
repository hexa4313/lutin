#include <iostream>
#include <vector>

#include "program.h"
#include "instruction/read.h"
#include "instruction/write.h"
#include "instruction/assign.h"


void Program::toString(std::ostream &o) const {
	o << *m_decList << *m_instList;
}

bool Program::StaticAnalysis(){
	//Take back every declaration
	auto declarations = m_decList->getDecs();

	//Take back every declared instructions
	auto instructions = m_instList->getInsts();

	//Check if every instructions' variables are declared
	for (auto instruction : instructions) {
		//Iterators in varDec and constDec
		//std::vector<std::shared_ptr<Symbol>>::iterator itVar = varDec.begin();
		//std::vector<std::shared_ptr<Symbol>>::iterator itVar = declarations.begin();
		//std::vector<std::shared_ptr<Symbol>>::iterator itConst = constDec.begin();

		//Verify which type of instructions we have here
		if (instruction->getType() == SymbolType::I_R) {
			auto read = std::dynamic_pointer_cast <Read> (instruction);
			
			auto dec = m_decList->getDec(read->getId());
		        if(dec && dec->getType() == SymbolType::CST) {
				//Variable of read instruction found as a constant
				//Error : Impossible to modify a constant
		      	}
		      	else {
				//Variable of read instruction not found
				//Error : Variable not declared
		      	}

		} else if (instruction->getType() == SymbolType::I_W) {
			auto wrInst = std::dynamic_pointer_cast <Write> (instruction);

    			auto wrExpr = wrInst->getWrExpr();

			//Take back variables composing the expression
			//std::vector<std::shared_ptr<Variable>> varVect = wrExpr->getBackVar();
		} else if (instruction->getType() == SymbolType::AFF) {
			auto asInst = std::dynamic_pointer_cast <Assign> (instruction);
			std::string asVar = asInst->getAsVar();
			std::shared_ptr<Expression> asExpr = asInst->getAsExpr();
		}
	}
	return true;
}
