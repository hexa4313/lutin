#include <iostream>
#include <vector>

#include "program.h"
#include "declaration/vardec.h"
#include "declaration/constdec.h"
#include "instruction/read.h"

bool Program::StaticAnalysis(){
	//Take back every declaration
	std::vector<std::shared_ptr<Declaration>> decList = m_decList->getDecs();
	//Take back declared variables and constants separated in different vectors
	std::vector<std::shared_ptr<Symbol>> varDec;
	std::vector<std::shared_ptr<Symbol>> constDec;
	std::vector<std::shared_ptr<Declaration>>::iterator itDec;
	for (itDec = decList.begin() ; itDec != decList.end() ; itDec++) {
		if ((*itDec)->getType() == SymbolType::V) {
			std::vector<std::shared_ptr<Symbol>> varDecTemp = (*itDec)->getDecList();
			varDec.insert(varDec.begin(), varDecTemp.begin(), varDecTemp.end() );
		} else if ((*itDec)->getType() == SymbolType::C) {
			std::vector<std::shared_ptr<Symbol>> constDecTemp = (*itDec)->getDecList();
			constDec.insert(constDec.begin(), constDecTemp.begin(), constDecTemp.end() );
		}
	}

	//Take back every declared instructions
	std::vector<std::shared_ptr<Instruction>> insts = m_instList->getInsts();

	//Check if every instructions' variables are declared
	for (unsigned int i = 0 ; i < insts.size() ; i++) {
		std::shared_ptr<Instruction> currentInst = insts[i];
		
		//Verify which type of instructions we have here
		if (currentInst->getType() == SymbolType::I_R) {
			std::shared_ptr<Read> rdInst = std::dynamic_pointer_cast <Read> (currentInst);
			std::shared_ptr<Variable> rdVar = rdInst->getRdVar();
			
			//Searching in the vector of declared variables if we find the variable used for read instruction
			std::vector<std::shared_ptr<Symbol>>::iterator itVar = varDec.begin();
			while ( ((std::dynamic_pointer_cast<VarDec> (*itVar))->getName()) == (rdVar->getName()) && itVar != varDec.end() ) { itVar ++; }

			//Searching in the vector of declared constants if we find the variable used for read instruction
			std::vector<std::shared_ptr<Symbol>>::iterator itConst = constDec.begin();
			while ( ((std::dynamic_pointer_cast<ConstDec>(*itConst))->getName()) == (rdVar->getName()) && itConst != constDec.end() ) { itConst ++; }

			if ( itVar == varDec.end() ) {
				if ( itConst == constDec.end() ) {
					//Variable of read instruction not found
					//Error : Variable not declared
				} else {
					//Variable of read instruction found as a constant
					//Error : Impossible to modify a constant
				}
			} else {
				//Corresponding match found
				//Nothing to do, it's allright
			}
		}else if (currentInst->getType() == SymbolType::I_W) {

		}else if (currentInst->getType() == SymbolType::AFF) {

		}
	}
	return true;
}
