#include <iostream>
#include <vector>

#include "program.h"
#include "declaration/vardec.h"
#include "declaration/constdec.h"

/*
bool StaticAnalysis(){
	//Take back every declared variables
	std::vector<std::shared_ptr<VarDec>> varDec = m_decList.getDecs().getVars();
	//Take back every declared consts
	std::vector<std::shared_ptr<ConstDec>> constDec = m_decList.getDecs().getConsts();
	//Take back every declared instructions
	std::vector<std::shared_ptr<Instruction>> insts = m_instList.getInsts();

	//Check if every instructions' variables are declared
	for (int i = 0 ; i < insts.size() ; i++) {
		std::shared_ptr<Instruction> currentInst = insts[i];
		
		//Verify which type of instructions we have here
		if (currentInst.getType() == SymbolType::I_R) {
			std::shared_ptr<Variable> currentInst.getRdVar();
			
			//Searching in the vector of declared variables if we find the variable used for read instruction
			std::vector<std::shared_ptr<VarDec>>::iterator itVar = varDec.begin();
			while ( *itVar->m_name.compare(currentInst->m_name) != 0 && itVar != varDec.end() ) { itVar ++; }

			//Searching in the vector of declared constants if we find the variable used for read instruction
			std::vector<std::shared_ptr<ConstDec>>::iterator itConst = constDec.begin();
			while ( *itConst->m_name.compare(currentInst->m_name) != 0 && itConst != constDec.end() ) { itConst ++; }

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
		}else if (currentInst.getType() == SymbolType::I_W) {

		}else if (currentInst.getType() == SymbolType::AFF) {

		}
	}
}
*/
